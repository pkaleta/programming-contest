package com.gra;

import com.gralib.*;

/**
 *
 * @author mind, pparys
 */
public class Plansza extends PlanszaA {
    public static final int GRACZ[] = {1, 2};
    public static final int SCIANA = 3;
    public static final int ANIM_RURKA = 4;
    private static final int KROK_ANIMACJI = 3; // o ile przesuwac
    private static final int TEMPO_LANIA = 5; // co ile lejemy
    public int[][] co;
    public int[][] dir; // 0 = w prawo, 1 = w lewo

    public Plansza()
    {
        co = new int[SIZE_X][SIZE_Y];
        dir = new int[SIZE_X][SIZE_Y];
    }

    public PlanszaA kopiuj() {
        Plansza pl = new Plansza();
        for (int x = 0; x<SIZE_X; ++x)
            for (int y = 0; y<SIZE_Y; ++y) {
                pl.co[x][y] = co[x][y];
                pl.dir[x][y] = dir[x][y];
            }
        return pl;
    }

    public void przesun(int x0, int y0, int x1, int y1) {
        co[x1][y1] = co[x0][y0];
        co[x0][y0] = 0;
        dir[x1][y1] = x1>=x0 ? 0 : 1;
    }

    public void zamuruj(int x, int y) {
        co[x][y] = SCIANA;
        dir[x][y] = 0;
    }

    // stan poczatkowy
    public void czysc() {
        selected = false;
        for (int x = 0; x < SIZE_X; x++)
            for (int y = 0; y < SIZE_Y; y++)
                dir[x][y] = co[x][y] = 0;
        co[0][3] = co[3][0] = co[9][3] = co[6][0] = GRACZ[0];
        co[0][6] = co[3][9] = co[9][6] = co[6][9] = GRACZ[1];
    }
    
    public boolean czyMoznaStadRuszyc(int nrGracza, int x, int y) {
        int dx[] = {1, 1, -1, -1, 1, -1, 0, 0};
        int dy[] = {1, -1, 1, -1, 0, 0, 1, -1};
        if (co[x][y]==GRACZ[nrGracza])
            for (int d = 0; d<8; ++d)
                if (x+dx[d]>=0 && x+dx[d]<SIZE_X && y+dy[d]>=0 && y+dy[d]<SIZE_Y
                    && co[x+dx[d]][y+dy[d]]==0)
                    return true;
        return false;
    }
    
    public String czyMoznaTamRuszycLubStrzelic(int x0, int y0, int x1, int y1) {
        if ((x0==x1) && (y0==y1))
            return "Pole zrodlowe i docelowe pokrywaja sie";
        if (!(x0==x1 || y0==y1 || Math.abs(x1-x0)==Math.abs(y1-y0)))
            return "Pole docelowe nie w linii prostej";
        int dx = x1>x0 ? 1 : x1<x0 ? -1 : 0;
        int dy = y1>y0 ? 1 : y1<y0 ? -1 : 0;
        while (x0!=x1 || y0!=y1) {
            x0 += dx;
            y0 += dy;
            if (co[x0][y0]!=0)
                return "Proba przejscia lub strzalu przez zajete pole";
        }
        return null;
    }
    
    public boolean czyKoniecGry(int nrGracza) {
        for (int x = 0; x<SIZE_X; ++x)
            for (int y = 0; y<SIZE_Y; ++y)
                if (co[x][y]==GRACZ[nrGracza] && czyMoznaStadRuszyc(nrGracza, x, y))
                    return false;
        return true;
    }

//////////////// ANIMACJE ////////////////////

    public boolean anim = false; // plansza w stanie animacji (cos jest na wspolrzednej niecalkowitej)
    public int animx, animy;
    public int animco, animdir;
    public int animrurkax0, animrurkay0;

    private void przeliczAnim(int x0, int y0, int x1, int y1) {
        animx = KPlansza.xEkranowy(x0);
        animy = KPlansza.yEkranowy(y0);
        final int celx = KPlansza.xEkranowy(x1);
        final int cely = KPlansza.yEkranowy(y1);
        final int adx = x1>x0 ? 1 : x1<x0 ? -1 : 0;
        final int ady = y1>y0 ? 1 : y1<y0 ? -1 : 0;
        animdir = adx>=0 ? 0 : 1;
        anim = true;
        animNastepnaKlatka = new Runnable() {
            public void run() {
                for (int a = 0; a<KROK_ANIMACJI; ++a) {
                    animx += adx;
                    animy += ady;
                    if (animx==celx && animy==cely) {
                        animNastepnaKlatka = null;
                        break;
                    }
                }
            }
        };
    }

    public void animujPrzesuniecie(int x0, int y0, int x1, int y1) {
        animco = co[x0][y0];
        co[x0][y0] = 0;
        selected = false;
        przeliczAnim(x0, y0, x1, y1);
    }

    public void animujStrzal(final int x0, final int y0, final int x1, final int y1) {
        selected = false;
        animco = ANIM_RURKA+co[x0][y0]-1;
        przeliczAnim(x0, y0, x1, y1);
        animrurkax0 = animx;
        animrurkay0 = animy;
        animNastepnyEtap = new Runnable() {
            public void run() {
                co[x1][y1] = SCIANA;
                dir[x1][y1] = Zasoby.SCIANA_ILE-1;
                animNastepnaKlatka = new Runnable() {
                    int zm = 0;
                    public void run() {
                        zm = (zm+1)%TEMPO_LANIA;
                        if (zm==0 && --dir[x1][y1]==0)
                            animNastepnaKlatka = null;
                    }
                };
                animNastepnyEtap = new Runnable() {
                    public void run() {
                        przeliczAnim(x1, y1, x0, y0);
                    }
                };
            }
        };
    }

    // poczatek animacji
    public void animujRuch(RuchA ruch0) {
        final Ruch ruch = (Ruch)ruch0;
        final int buf = co[ruch.x0][ruch.y0];
        animujPrzesuniecie(ruch.x0, ruch.y0, ruch.x1, ruch.y1);
        animNastepnyEtap = new Runnable() {
            public void run() {
                co[ruch.x1][ruch.y1] = buf;
                dir[ruch.x1][ruch.y1] = animdir;
                animujStrzal(ruch.x1, ruch.y1, ruch.x2, ruch.y2);
            }
        };
    }
}

