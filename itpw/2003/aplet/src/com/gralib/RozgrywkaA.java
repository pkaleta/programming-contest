package com.gralib;

import com.gralib.utils.Utils;

import javax.swing.*;
import java.awt.event.*;
import java.awt.EventQueue;
import java.util.Vector;

/**
 *
 * @author pparys
 */
public abstract class RozgrywkaA {

    public GraczA gracze[];
    
    public class Stan {
        public PlanszaA plansza;
        public int numerTury = 0, numerPoltury = 0;
        public int numerGracza = 0; // kto sie teraz rusza
    }
    
    public Stan stanOst = new Stan(), stanCur = new Stan();
    public PlanszaA planszaWysw;
    
    public boolean finished = false;
    public String status = "Gra trwa";
    public static boolean wstepne = false; // wykonywanie ruchow z logu tylko zeby je wczytac

    public boolean paused = false;
    public boolean liczeRuchWTle = false;
    
    private Vector historia = new Vector();
    private Vector wiadomosci = new Vector();
    public GlownyCzytacz glownyCzytacz;
    
    public Runnable anulujL = null;

    /** Wykonywane raz na poczatku gry. Zaczyna grac. */
    public final void inicjujGre(GraczA[] gracze, GlownyCzytacz glCz, int ilePlikowych) {
        timerDalej.setCoalesce(false);
        timerAnimacja.setCoalesce(false);
        glownyCzytacz = glCz;
        timerDalej.setRepeats(false);
        timerAnimacja.setRepeats(false);
        this.gracze = gracze;
        planszaWysw = stanCur.plansza = (PlanszaA)Main.newInstance(Ustawienia.planszaC);
        stanPoczatkowy();
        stanOst.plansza = stanCur.plansza.kopiuj();
        GraczLog.startMain(ilePlikowych==0);
        for (int a = 0; a<Ustawienia.ileGraczy; ++a)
            gracze[a].daj(""+(a+1)+Utils.EOL);
        if (ilePlikowych==Ustawienia.ileGraczy) {
            // wykonaj wszystkie ruchy w tle (sprawdzajac poprawnosc)
            wstepne = true;
            while (!finished)
                przygotujDoRuchu();
            wstepne = false;
        }
        Main.og.odswiezInformacje();
        Main.og.odswiezPrzyciski();
        Main.og.plansza.repaint();
        wykonajKrok();
    }
    
    /** wywolywane raz na koncu gry */
    private boolean stoped = false;
    public final void stop() {
        if (stoped)
            return;
        stoped = true;
        for (int a = 0; a<Ustawienia.ileGraczy; ++a)
            gracze[a].stop();
        GraczLog.stopMain();
    }

    private final void stanPoczatkowy() {
        stanCur.plansza.czysc();
        stanCur.numerPoltury = 0;
        stanCur.numerTury = 0;
        stanCur.numerGracza = 0;
    }
    
    public final void anulujMyszowego() {
        if (anulujL!=null && liczeRuchWTle) {
            anulujL.run();
            liczeRuchWTle = false;
        }
    }
    
    public final void ustawPolture(int nr) {
        if (nr==stanCur.numerPoltury)
            return;
        anulujMyszowego();
        anulujAnimacje();
        if (nr<stanCur.numerPoltury)
            stanPoczatkowy();
        while (stanCur.numerPoltury<nr)
        {
            zrobRuch(stanCur, (RuchA)historia.get(stanCur.numerPoltury));
            nastepnaPoltura(stanCur);
        }
        planszaWysw = stanCur.plansza; // mozna nie kopiowac
        Main.og.odswiezInformacje();
        Main.og.plansza.repaint();
        if (!paused)
            timerDalej.start();
    }
    
    public final void przygotujDoRuchu() {
        if (this!=Main.og.rozgrywka || liczeRuchWTle)
            return;
        final GraczA aktualny = gracze[stanOst.numerGracza];
        aktualny.daj(inwokacja()+Utils.EOL);
        liczeRuchWTle = true;
        if (!wstepne)
            Main.og.odswiezInformacje(); // nr gracza
        final RozgrywkaA thisR = this;
        aktualny.wez(new RuchListener() {
            public void wykonanoRuch(boolean blad, String rs) {
                if (thisR!=Main.og.rozgrywka) 
                    return;
                liczeRuchWTle = false;

                boolean ruchWLogu = !(blad || rs==null);
                RuchA ruch = blad ? new BlednyRuch(rs)
                    : rs==null ? new BlednyRuch("Plik z ruchami za krotki")
                    : glownyCzytacz!=null && 
                        !rs.equals(glownyCzytacz.dajRuch(stanOst.numerPoltury))
                        ? new BlednyRuch(
                            "Program wykonal inny ruch niz zapisany w pliku - linia "
                            +(stanOst.numerPoltury+2))
                    : sprawdzRuch(stanOst, rs);

                if (ruchWLogu) // <- jesli w rs jest ruch, to go zapisz 
                    GraczLog.dajMain(rs+Utils.EOL);
                    // (nigdy nie zapisze sie, gdy jest blad wynikajacy z
                    // roznicy, bo jesli jest cos z pliku, to nie logujemy
                if (blad) // jedyna mozliwosc gdy nie wszytujemy z logu to "Blad komunikacji"
                    GraczLog.dajMain("-"+rs+Utils.EOL);
                    
                if (ruch.dajBlad()!=null) {
                    String zobacz = ruchWLogu ? 
                        "\nZobacz plik gracz"+(stanOst.numerGracza+1)+"_log.out" : "";
                    wiadomosci.add("Gracz o numerze "+(stanOst.numerGracza+1)
                        +" wykonal nieprawidlowy ruch!\n("+ruch.dajBlad()+")."+zobacz);
                    ruch = bylBlad();
                    rs = "";
                }
                else
                    wiadomosci.add(null);
                int nrPoltury = stanOst.numerPoltury;
                if (!finished)
                {
                    // wypisz ruch innym graczom i do loga
                    String line = ruch.ruchDlaInnegoGracza+Utils.EOL;
                    for (int a = 0; a<Ustawienia.ileGraczy; ++a)
                        if (a!=stanOst.numerGracza)
                            gracze[a].daj(line);
                    // inne dzialania
                    historia.add(ruch);
                    zrobRuch(stanOst, ruch);
                    nastepnaPoltura(stanOst);
                    sprawdzKoniecIKoncz();
                    if (finished)
                        wiadomosci.add(null); // wiadomosci zawsze jest o 1 wiecej
                }
                if (finished)
                    stop();
                if (!wstepne)
                {
                    Main.og.odswiezInformacje(); // nr gracza i max suwaka
                    if (stanCur.numerPoltury==nrPoltury && !paused)
                        wykonajKrok(aktualny.czyMyszowy());
                }
            }
        });
    }
    
    public Timer timerDalej = new Timer(Main.og.sterowanie.opoznienie, new ActionListener() {
        public void actionPerformed(ActionEvent e) {
            wykonajKrok();
        }
    });;

    private Timer timerAnimacja = new Timer(Ustawienia.czasKlatkiAnimacji, new ActionListener() {
        public void actionPerformed(ActionEvent e) {
            // Od suwania suwakiem powinno przestac animowac, ale
            // wykonajKrok powinno sie zrobic (po opoznieniu). Od naciskania
            // pauza/dalej powinno w ogole tutaj przerwac.
            if (planszaWysw.nastepnaKlatkaAnimacji()) {
                Main.og.plansza.repaint();
                timerAnimacja.start();
            }
            else {
                planszaWysw = stanCur.plansza; // bez kopiowania
                Main.og.plansza.repaint();
                // czekaj (odstep miedzy ruchami) i potem nastepny ruch
                // ale jesli teraz ma byc myszowy, to nie czekaj
                if (stanCur.numerPoltury==stanOst.numerPoltury && !finished
                    && gracze[stanOst.numerGracza].czyMyszowy())
                    wykonajKrok();
                else
                    timerDalej.start();
            }
        }
    });
    
    public final void anulujAnimacje() {
        timerDalej.stop();
        timerAnimacja.stop();
    }
    
    public final void wykonajKrok() {
        wykonajKrok(false);
    }

    public final void wykonajKrok(boolean nieAnim) {
        if (paused) 
            return;
        if (stanCur.numerPoltury==stanOst.numerPoltury && !finished)
        {
            przygotujDoRuchu();
            return;
        }
        if (wiadomosci.get(stanCur.numerPoltury)!=null)
            Utils.powiedzBlad((String)wiadomosci.get(stanCur.numerPoltury));
        if (stanCur.numerPoltury==stanOst.numerPoltury) {
            if (Main.og.useSound)
                playSound(true);
            Utils.powiedz(status);
            paused = true;
            Main.og.odswiezPrzyciski(); // przycisk Pauza
            return;
        }
        if (Main.og.useSound)
            playSound(false);
        if (Main.og.animuj && !nieAnim)
        {
            planszaWysw = stanCur.plansza.kopiuj();
            planszaWysw.animujRuch((RuchA)historia.get(stanCur.numerPoltury));
        }
        zrobRuch(stanCur, (RuchA)historia.get(stanCur.numerPoltury));
        nastepnaPoltura(stanCur);
        Main.og.odswiezInformacje();

        timerAnimacja.start();
}


///////////// Metody przeznaczone do ewentualnego nadpisywania ////////

    // Wywolywana, gdy ktorys gracz wykonal bledny ruch.
    // Musi ustawic finished lub zwrocic ruch zastepczy
    protected final RuchA bylBlad()
    {
        finished = true;
        if (Ustawienia.ileGraczy==2)
            status = "Wygral gracz "+(2-stanOst.numerGracza);
        else
            status = "Przegral gracz "+stanOst.numerGracza;
        return null;
    }

    protected final void nastepnaPoltura(Stan s) {
        ++s.numerPoltury;
        ++s.numerGracza;
        if (s.numerGracza>=Ustawienia.ileGraczy)
        {
            s.numerGracza = 0;
            ++s.numerTury;
        }
    }
    
    protected void playSound(boolean end) {}

    public String getPunkty(int nrGracza) {
      return null;
    }

/// Metody abstrakcyjne

    // co wypisac jako ¿±danie ruchu
    protected abstract String inwokacja();

    // jesli blad to zwroc null i zapisz blad w blad (wiadomo, ze rs!=null)
    protected abstract RuchA sprawdzRuch(Stan pl, String rs);

    protected abstract void zrobRuch(Stan pl, RuchA ruch);

    // jesli jest juz koniec gry na stanOst, to ustaw finished i status
    protected abstract void sprawdzKoniecIKoncz();

}
