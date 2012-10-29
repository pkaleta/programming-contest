package com.gralib.utils;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;
import java.io.File;

/**
 * Klasa ta potrafi wczytac klatki pewnej animacji.
 * Przeznaczona jest do uzycia jednorazowego w celu wczytania do
 * pamieci klatek.
 * @author Rafal Rusin
 */

public class KlatkiAnimacji {
    public ArrayList klatki = new ArrayList();

    /**
     * Konstruktor wczytuje obrazki animacji uzywajac nazwy pliku
     * nazwa+liczba+rozszerzenie, gdzie liczba jest dwucyfrowa
     * liczba klatki z zakresu 0..liczbaKlatek.
     * @param komponent komponent, na ktorym beda rysowane klatki animacji
     */
    public KlatkiAnimacji(String nazwa, int liczbaKlatek, String rozszerzenie, Component komponent) {
        MediaTracker tracker = new MediaTracker(komponent);

        for (int i = 0; i < liczbaKlatek; i++) {
            String s;
            s = Integer.toString(i);
            while (s.length() < 4) s = "0" + s;
            s = nazwa + s + rozszerzenie;

            ImageIcon icon = new ImageIcon(Toolkit.getDefaultToolkit().getImage(Utils.getResourceUrl(s)));
            klatki.add(icon);
            tracker.addImage(icon.getImage(), i);
        }

        //czekanie na wczytanie wszystkich klatek animacji
        try {
            tracker.waitForAll();
            if (tracker.isErrorAny()) {
                Utils.powiedzBlad("Blad w trakcie wczytywania animacji \""+nazwa+"\"");
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }

    /**
     * Zwraca klatke o numerze numer
     */
    public ImageIcon wez(int numer) {
        return (ImageIcon)klatki.get(numer);
    }

    /**
     * Zwraca ilosc klatek
     */
    public int rozmiar() {
        return klatki.size();
    }
}

