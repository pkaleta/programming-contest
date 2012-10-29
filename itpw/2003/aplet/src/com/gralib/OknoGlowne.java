package com.gralib;

import com.gralib.utils.Utils;
//import com.gralib.utils.Zasoby;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.event.*;
import java.util.ArrayList;
import java.util.Iterator;
import java.io.*;

/**
 *
 * @author mind, pparys
 */

public abstract class OknoGlowne {

    protected JFrame frame;

    public KWyborGracza[] wybor;
    public KInfo info;
    public KPlanszaA plansza;

    public JScrollBar sbRuch;

    public boolean useSound;
    public boolean animuj;

    public RozgrywkaA rozgrywka;

    public KSterowanie sterowanie;

    public final void finalInitialization()
    {
        sbRuch.setOrientation(JScrollBar.HORIZONTAL);
        sbRuch.setVisibleAmount(Ustawienia.szerokoscSuwaka);
        sbRuch.setMinimum(0);
        sbRuch.getModel().addChangeListener(new ChangeListener() {
            public void stateChanged(ChangeEvent e) {
                if (rozgrywka!=null)
                    rozgrywka.ustawPolture(sbRuch.getValue());
            }
        });
        frame.pack();
        odswiezInformacje();
        odswiezPrzyciski();
        plansza.repaint();
    }

    public OknoGlowne() {
        animuj = Ustawienia.jestAnimacja;
        useSound = Ustawienia.jestDzwiek;
        frame = Main.mainFrame;
        Main.og = this;
        frame.setDefaultCloseOperation(frame.EXIT_ON_CLOSE);
    }

    public final void nowaGra() {
        koniecGry();
        GraczA[] gracze = new GraczA[Ustawienia.ileGraczy];
        int ile_plikowych = 0;
        int ile_ok = 0;
        GlownyCzytacz glownyCzytacz = null;
        try {
            String nazwaPlikuZLogami = null;
            for (int a = 0; a<Ustawienia.ileGraczy; ++a)
                if (wybor[a].czyPlikowy()) {
                    nazwaPlikuZLogami = wybor[a].getPolePlikowe().getNazwa().getText();
                    ++ile_plikowych;
                }
            if (ile_plikowych>0)
                glownyCzytacz = new GlownyCzytacz(nazwaPlikuZLogami);
            for (int a = 0; a<Ustawienia.ileGraczy; ++a) {
                gracze[a] = wybor[a].stworzGracza();
//                if (!wybor[a].czyPlikowy())
                gracze[a] = new GraczLog(gracze[a], "gracz"+(a+1));
            }
        } catch (Exception e) {
            for (int a = 0; a<ile_ok; ++a)
              gracze[a].stop();
            Main.og.koniecGry();
            Utils.powiedzWyjatek(e);
            return;
        }
        rozgrywka = (RozgrywkaA)Main.newInstance(Ustawienia.rozgrywkaC);
        rozgrywka.inicjujGre(gracze, glownyCzytacz, ile_plikowych);
    }

    public final void koniecGry() {
        if (rozgrywka!=null)
            rozgrywka.stop();
        rozgrywka = null;
        odswiezInformacje();
        odswiezPrzyciski();
        plansza.repaint();
    }

    public final void zapauzuj() {
        if (rozgrywka!=null)
            rozgrywka.paused = true;
        odswiezPrzyciski();
    }

    public final void odpauzuj() {
        if (rozgrywka!=null)
        {
            rozgrywka.paused = false;
            rozgrywka.anulujAnimacje();
            rozgrywka.wykonajKrok();
        }
        odswiezPrzyciski();
    }

    public final void odswiezInformacje() {
        for (int a = 0; a<Ustawienia.ileGraczy; ++a) {
            if (Ustawienia.wyswietlPunkty)
                wybor[a].punkty.setText(rozgrywka==null ? " " : 
                    ("Punkty: "+rozgrywka.getPunkty(a))); 
            wybor[a].czas.setText(rozgrywka==null || rozgrywka.gracze[a].getCzas()<0 ? " " :
                ("Czas: "+rozgrywka.gracze[a].getCzas()+" ms"));
        }
        if (rozgrywka==null || !rozgrywka.liczeRuchWTle)
            info.ustawStan(-1);
        else
            info.ustawStan(rozgrywka.stanOst.numerGracza);
        if (rozgrywka==null) {
            info.ustawTure(0);
            sbRuch.setValue(0);
            sbRuch.setEnabled(false);
            sbRuch.setMaximum(Ustawienia.szerokoscSuwaka); 
        }
        else {
            info.ustawTure(rozgrywka.stanCur.numerTury);
            sbRuch.setValue(rozgrywka.stanCur.numerPoltury);
            sbRuch.setEnabled(true);
            sbRuch.setMaximum(rozgrywka.stanOst.numerPoltury+Ustawienia.szerokoscSuwaka); 
        }
    }

    public final void odswiezPrzyciski() {
        if (rozgrywka==null)
            sterowanie.wylaczPauze();
        else
        if (rozgrywka.paused)
            sterowanie.ustawDalej();
        else
            sterowanie.ustawPauze();
    }

    public final void show() {
        frame.show();
    }
    
    public final void zmienionoOpoznienie() {
        if (rozgrywka!=null)
            rozgrywka.timerDalej.setInitialDelay(sterowanie.opoznienie);
    }
}
