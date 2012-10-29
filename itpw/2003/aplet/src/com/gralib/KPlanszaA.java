package com.gralib;

import com.gralib.utils.*;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.BufferedImage;

/**
 *
 * @author mind, pparys
 */
public abstract class KPlanszaA extends Canvas {

    protected static int ROZMIAR_X, ROZMIAR_Y;

    protected Image bufi = null; // bufor

    private static KlatkiAnimacji background = null;
    protected static ImageIcon tloKratki=null;

    public KPlanszaA(KlatkiAnimacji bg) {
        background = bg;
    }
    
    private void przygotujTlo() {
        ImageIcon i = background.wez(0);
        int rx, ry;
        rx = PlanszaA.SIZE_X * ROZMIAR_X+1;
        ry = PlanszaA.SIZE_Y * ROZMIAR_Y+1;
        Image i2 = new BufferedImage(rx, ry, BufferedImage.TYPE_INT_ARGB);
        Graphics g = i2.getGraphics();
        drawTiled(i, 0, 0, rx, ry, g);
        g.setColor(new Color(0, 0, 0, 64));
        for (int x=0; x<rx; x += ROZMIAR_X)
            g.drawLine(x, 0, x, ry);
        for (int y=0; y<ry; y += ROZMIAR_Y)
            g.drawLine(0, y, rx, y);
        tloKratki = new ImageIcon(i2);
    }

    protected abstract void rysujPole(PlanszaA p, int px, int py, int ex, int ey, Graphics g);

    protected void rysujDodatki(PlanszaA p, Graphics g) {}

    public final void paint(Graphics g) {
        update(g);
    }

    protected final void drawImg(ImageIcon icon, int x, int y, Graphics g) {
        g.drawImage(icon.getImage(), x - icon.getIconWidth() / 2, y - icon.getIconHeight() / 2, this);
    }


    public final void update(Graphics g) {

        if (tloKratki==null)
            przygotujTlo();

        Dimension d = getSize();
        if (bufi == null || bufi.getWidth(this) != d.width || bufi.getHeight(this) != d.height) {
            bufi = createImage(d.width, d.height);
        }
        Graphics bufg = bufi.getGraphics();

        drawBackground(bufg);
        if (Main.og.rozgrywka!=null)
        {
            PlanszaA plansza = Main.og.rozgrywka.planszaWysw;
            drawForEach(plansza, bufg);

            // rysuj obwodke dookola zaznaczonego pola
            if (plansza.selected) {
                bufg.setColor(Ustawienia.kolorZaznaczenia);
                int x0 = plansza.selx*ROZMIAR_X, y0 = plansza.sely*ROZMIAR_Y;
                int x1 = x0+ROZMIAR_X, y1 = y0+ROZMIAR_Y;
                bufg.drawLine(x0, y0, x1, y0);
                bufg.drawLine(x1, y0, x1, y1);
                bufg.drawLine(x1, y1, x0, y1);
                bufg.drawLine(x0, y1, x0, y0);
            }
            rysujDodatki(plansza, bufg);
        }

        g.drawImage(bufi, 0, 0, this);
    }

    private void drawTiled(ImageIcon i, int x, int y, int width, int height, Graphics g) {
        int iw = i.getIconWidth(), ih = i.getIconHeight();
        Image im = i.getImage();
        int px = 0,py = 0;
        while (py < height) {
            int w = height - py;
            if (w > ih) w = ih;
            while (px < width) {
                int s = width - px;
                if (s > iw) s = iw;
                g.drawImage(im, x+px, y+py, x+px + s, y+py + w, 0, 0, s, w, this);
                px += s;
            }
            px = 0;
            py += w;
        }
    }

    private void drawBackground(Graphics g) {
        g.drawImage(tloKratki.getImage(), 0, 0, this);
    }

    public final static int xEkranowy(int x) {
        return x*ROZMIAR_X+ROZMIAR_X/2;
    }

    public final static int yEkranowy(int y) {
        return y*ROZMIAR_Y+ROZMIAR_Y/2;
    }

    private void drawForEach(PlanszaA model, Graphics g) {
        for (int y = model.SIZE_Y - 1; y >= 0; y--) {
            for (int x = 0; x < model.SIZE_X; x++) {
                int ex = xEkranowy(x), ey = yEkranowy(y);
                rysujPole(model, x, y, ex, ey, g);
            }
        }
    }

    public final Dimension getPreferredSize() {
        if (ROZMIAR_X<=0 || ROZMIAR_Y<=0)
            Utils.powiedzBlad(
                "KPlanszaA.getPreferredSize: BLAD! Nie ustawiono rozmiarow pola!");
        if (PlanszaA.SIZE_X<=0 || PlanszaA.SIZE_Y<=0)
            Utils.powiedzBlad(
                "KPlanszaA.getPreferredSize: BLAD! Nie ustawiono rozmiarow planszy!");
        Dimension d;
        d = new Dimension(PlanszaA.SIZE_X * ROZMIAR_X, PlanszaA.SIZE_Y * ROZMIAR_Y);
        return d;
    }
    
    MouseListener ml = null;
    
    public final void ustawML(MouseListener ml_) {
        if (ml!=null)
            removeMouseListener(ml);
        ml = ml_;
        if (ml!=null)
            addMouseListener(ml);
    }
}
