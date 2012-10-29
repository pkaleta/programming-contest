package com.gralib;

import java.util.Vector;
import javax.swing.*;
import java.awt.event.*;

/**
 *
 * @author pparys
 */
public abstract class GraczMyszA extends GraczA {

    private RuchListener rl;
    private Vector plansze;
    private Vector polruchy;
    
    protected abstract boolean czyKlikOk(PlanszaA pl, PolruchA s0, int x, int y);
    protected abstract void wykonajKlik(PlanszaA pl, PolruchA s0, int x, int y); // zmienia pl i s0
    protected void animujKlik(PlanszaA pl, PolruchA s0, int x, int y) { // zmienia pl
    }
    
    protected final int nrGracza() {
        return Main.og.rozgrywka.stanOst.numerGracza;
    }

    private Timer timerAnimacja = new Timer(Ustawienia.czasKlatkiAnimacji, new ActionListener() {
        public void actionPerformed(ActionEvent e) {
            if (Main.og.rozgrywka.planszaWysw.nastepnaKlatkaAnimacji()) {
                Main.og.plansza.repaint();
                timerAnimacja.start();
            }
            else {
                Main.og.rozgrywka.planszaWysw = (PlanszaA)plansze.lastElement(); // bez kopiowania
                Main.og.plansza.repaint();
                PolruchA r0 = (PolruchA)polruchy.lastElement();
                if (r0.czyCaly()) {
                    anuluj();  // koniec pytania o ruch
                    rl.mamRuch(false, r0.zamienNaRuch());
                }
            }
        }
    });

    public GraczMyszA() {
        timerAnimacja.setCoalesce(false);
        timerAnimacja.setRepeats(false);
    }
    
    private MouseListener listener = new MouseListener(){
        public void mouseClicked(MouseEvent e) {
            int x0 = e.getX() / KPlanszaA.ROZMIAR_X;
            int y0 = e.getY() / KPlanszaA.ROZMIAR_Y;
            PlanszaA pl = (PlanszaA)plansze.lastElement();
            PolruchA s0 = (PolruchA)polruchy.lastElement();
            if (!PlanszaA.naPlanszy(x0, y0) || !czyKlikOk(pl, s0, x0, y0))
                return;
            timerAnimacja.stop();
            pl = pl.kopiuj();
            s0 = s0.kopiuj();
            if (Main.og.animuj) {
                PlanszaA wpl = Main.og.rozgrywka.planszaWysw = pl.kopiuj();
                animujKlik(wpl, s0, x0, y0);
            }
            wykonajKlik(pl, s0, x0, y0);
            plansze.add(pl);
            polruchy.add(s0);
            timerAnimacja.start();
        }
        public void mouseReleased(MouseEvent e) {}
        public void mousePressed(MouseEvent e) {}
        public void mouseExited(MouseEvent e) {}
        public void mouseEntered(MouseEvent e) {}
    };
    
    protected final void anuluj() {
        timerAnimacja.stop();
        Main.og.plansza.ustawML(null);
        if (Main.og.rozgrywka!=null)
            Main.og.rozgrywka.anulujL = null;
    }

    public final void wez(RuchListener rl) {
        this.rl = rl;
        plansze = new Vector();
        polruchy = new Vector();
        plansze.add(Main.og.rozgrywka.stanOst.plansza);
        polruchy.add(Main.newInstance(Ustawienia.polruchC));
        Main.og.plansza.ustawML(listener);
        Main.og.rozgrywka.anulujL = new Runnable() {
            public void run() {
                anuluj();
            }
        };
    }

    public final void daj(String tekst) {}
    
    public final void stop() {
        anuluj();
    }
    
    public final boolean czyMyszowy() {
        return true;
    }
}
