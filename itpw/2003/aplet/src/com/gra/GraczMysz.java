package com.gra;

import com.gralib.*;

/**
 *
 * @author pparys
 */
public class GraczMysz extends GraczMyszA {

    protected boolean czyKlikOk(PlanszaA pl0, PolruchA s00, int x, int y) {
        Plansza pl = (Plansza)pl0;
        Polruch s0 = (Polruch)s00;
        if (s0.e==0)
            return pl.czyMoznaStadRuszyc(nrGracza(), x, y);
        if (s0.e==1 && pl.czyMoznaStadRuszyc(nrGracza(), x, y))
            return true; // wybor innej betoniarki
        return pl.czyMoznaTamRuszycLubStrzelic(s0.x[s0.e-1], s0.y[s0.e-1], x, y)==null;
    }
    
    protected void wykonajKlik(PlanszaA pl0, PolruchA s00, int x, int y) { // zmienia pl i s0
        Plansza pl = (Plansza)pl0;
        Polruch s0 = (Polruch)s00;
        if (s0.e==1 && pl.czyMoznaStadRuszyc(nrGracza(), x, y))
          s0.e = 0;	// wybor innej betoniarki
        s0.x[s0.e] = x;
        s0.y[s0.e] = y;
        if (s0.e<=1) {
            pl.selected = true;
            pl.selx = x;
            pl.sely = y;
        }
        if (s0.e==1)
            pl.przesun(s0.x[0], s0.y[0], x, y);
        if (s0.e==2) {
            pl.selected = false;
            pl.zamuruj(x, y);
        }
        ++s0.e;
    }

    protected void animujKlik(PlanszaA pl0, PolruchA s00, int x, int y) { // zmienia pl
        Plansza pl = (Plansza)pl0;
        Polruch s0 = (Polruch)s00;
        if (s0.e==1 && pl.czyMoznaStadRuszyc(nrGracza(), x, y))
          s0.e = 0;	// wybor innej betoniarki
        if (s0.e==0)
            return;
        if (s0.e==1)
            pl.animujPrzesuniecie(s0.x[0], s0.y[0], x, y);
        else
            pl.animujStrzal(s0.x[1], s0.y[1], x, y);
    }

}
