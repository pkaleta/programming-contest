package com.gra;

import com.gralib.*;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
//import java.awt.image.BufferedImage;

/**
 *
 * @author mind, pparys
 */
public class KPlansza extends KPlanszaA {
    private static final int WZWYZ = 12;
    private static final int SZERA = 3, SZERB = 2;

    public KPlansza() {
        super(Zasoby.background);
        ROZMIAR_X = 40;
        ROZMIAR_Y = 40;
    }

    protected void rysujPole(PlanszaA pl, int px, int py, int ex, int ey, Graphics g)
    {
        Plansza p = (Plansza)pl;
        //rysowanie pojedynczego pola
        if (p.co[px][py]!=0)
            drawImg(Zasoby.znaczek[p.co[px][py]-1].wez(p.dir[px][py]), ex, ey, g);
    }

    protected void rysujDodatki(PlanszaA pl, Graphics g) {
        Plansza p = (Plansza)pl;
        if (p.anim) {
            if (p.animco>=Plansza.ANIM_RURKA) {
                int x0 = p.animrurkax0, y0 = p.animrurkay0-WZWYZ;
                int x1 = p.animx, y1 = p.animy-WZWYZ;
                int dx = x1>x0 ? 1 : x1<x0 ? -1 : 0;
                int dy = y1>y0 ? 1 : y1<y0 ? -1 : 0;
                if (dx!=0 && dy!=0) { 
                    dx *= SZERB; 
                    dy *= SZERB;
                } else { 
                    dx *= SZERA; 
                    dy *= SZERA;
                }
                int x[] = {x0-dy, x0+dy, x1+dy, x1-dy};
                int y[] = {y0+dx, y0-dx, y1-dx, y1+dx};
                g.setColor(p.animco==Plansza.ANIM_RURKA ? Color.CYAN : Color.MAGENTA);
                g.fillPolygon(x, y, 4);
                g.setColor(p.animco==Plansza.ANIM_RURKA ? Color.BLUE : Color.RED);
                g.drawPolygon(x, y, 4);
            } else
                drawImg(Zasoby.znaczek[p.animco-1].wez(p.animdir), p.animx, p.animy, g);
        }
    }

}
