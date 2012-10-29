package com.gralib;

import javax.swing.*;
import java.awt.*;

/**
 *
 * @author mind, pparys
 */
public final class KInfo extends JPanel {
    private JLabel tura, stan;

    public KInfo() {
        setLayout(new GridLayout(2, 1));
        add(tura = new JLabel());
        add(stan = new JLabel());
        ustawTure(0);
        ustawStan(-1);
    }

    public void ustawTure(int numer) {
        tura.setText("Ruch nr: " + (numer+1));
    }

    /** <0 - nic, 0 - czekam na gracza 1, 1 - czekam na gracza 2, itd */
    public void ustawStan(int s) {
        String q = s<0 ? "-" : (""+(s+1));
        stan.setText("Czekam na gracza: "+q);
    }
}
