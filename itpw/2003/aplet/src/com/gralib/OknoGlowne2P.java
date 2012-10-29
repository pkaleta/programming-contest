package com.gralib;

import javax.swing.*;
import java.awt.*;

/**
 *
 * @pparys
 */

public final class OknoGlowne2P extends OknoGlowne {

    public OknoGlowne2P() {
        wybor = new KWyborGracza[Ustawienia.ileGraczy];

        JPanel c = new JPanel();
        c.setLayout(new BorderLayout());

        JPanel c1 = new JPanel();
        c1.setLayout(new BoxLayout(c1, BoxLayout.Y_AXIS));
        c1.setBorder(BorderFactory.createEtchedBorder());
        c1.add(info = new KInfo());
        c1.add(sbRuch = new JScrollBar());
        c1.add(sterowanie = new KSterowanie());
        c.add(c1, BorderLayout.CENTER);

        JPanel[] c3 = new JPanel[2];
        c3[0] = new JPanel();
        c3[1] = new JPanel();
        for (int i = 0; i < 2; ++i) {
            c3[i] = new JPanel();
            c3[i].setLayout(new BoxLayout(c3[i], BoxLayout.Y_AXIS));
            String s = "";
            if (Ustawienia.nazwyGraczy!=null)
                s = " ("+Ustawienia.nazwyGraczy[i]+")";
            c3[i].setBorder(BorderFactory.createTitledBorder("Gracz nr " + (i + 1) + s));
            c3[i].add(wybor[i] = new KWyborGracza());
            c.add(c3[i], i==1 ? BorderLayout.EAST : BorderLayout.WEST);
        }

        JPanel kp = new JPanel();
        plansza = (KPlanszaA)Main.newInstance(Ustawienia.kPlanszaC);
        kp.add(plansza);

        Container p = frame.getContentPane();
        p.setLayout(new BorderLayout());
        p.add(c, BorderLayout.NORTH);
        p.add(kp, BorderLayout.SOUTH);

        finalInitialization();
    }
}
