package com.gra;

import com.gralib.*;
import java.util.*;

/**
 *
 * @author pparys
 */
public class Rozgrywka extends RozgrywkaA {

    protected void playSound(boolean end) {
        (end ? Zasoby.dieS : Zasoby.tickS).play();
    }

    // co wypisac jako ¿±danie ruchu
    protected String inwokacja() {
        long cz = gracze[stanOst.numerGracza].getCzas(); 
        if (cz<0) 
            cz = 0;
        return ""+((1000*KSterowanie.czas-cz)/1000); // czas do konca
    }

    // jesli blad to zwroc null i zapisz blad w blad (wiadomo, ze rs!=null)
    protected RuchA sprawdzRuch(Stan st, String rs) {
        Plansza pl = (Plansza)st.plansza.kopiuj();
        StringTokenizer t = new StringTokenizer(rs);
        int tab[] = new int[6];
        try {
            for (int a = 0; a<6; ++a) {
                tab[a] = Integer.parseInt(t.nextToken());
                --tab[a];
            }
        } catch (NumberFormatException ex) {
            return new BlednyRuch("Niepoprawne znaki na wejsciu");
        } catch (NoSuchElementException ex) {
            return new BlednyRuch("Za malo liczb w linii");
        }
        if (t.hasMoreTokens())
            return new BlednyRuch("Za duzo liczb w linii");
        if (!Plansza.naPlanszy(tab[0], tab[1]) || !Plansza.naPlanszy(tab[2], tab[3])
            || !Plansza.naPlanszy(tab[4], tab[5]))
            return new BlednyRuch("Wskazane pole znajduje sie poza plansza");
        if (pl.co[tab[0]][tab[1]]==Plansza.GRACZ[1-st.numerGracza])
            return new BlednyRuch("Proba ruchu nie swoja postacia");
        if (pl.co[tab[0]][tab[1]]!=Plansza.GRACZ[st.numerGracza])
            return new BlednyRuch("Proba ruchu z pustego pola");
        String s1 = pl.czyMoznaTamRuszycLubStrzelic(tab[0], tab[1], tab[2], tab[3]);
        if (s1!=null)
            return new BlednyRuch(s1);
        pl.przesun(tab[0], tab[1], tab[2], tab[3]);
        s1 = pl.czyMoznaTamRuszycLubStrzelic(tab[2], tab[3], tab[4], tab[5]);
        if (s1!=null)
            return new BlednyRuch(s1);
        return new Ruch(rs, tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]);
    }

    protected void zrobRuch(Stan st, RuchA ruch) {
        Plansza pl = (Plansza)st.plansza;
        Ruch r = (Ruch)ruch;
        pl.przesun(r.x0, r.y0, r.x1, r.y1);
        pl.zamuruj(r.x2, r.y2);
    }

    // jesli jest juz koniec gry na stanOst, to ustaw finished i status
    protected void sprawdzKoniecIKoncz() {
        if (((Plansza)stanOst.plansza).czyKoniecGry(stanOst.numerGracza)) {
            status = "Wygral gracz "+(2-stanOst.numerGracza);
            finished = true;
        }
    }

}
