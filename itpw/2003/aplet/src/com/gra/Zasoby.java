package com.gra;

import java.awt.*;
import java.applet.AudioClip;
import com.gralib.utils.*;

/**
 *
 * @author pparys
 */
public class Zasoby {
    public static KlatkiAnimacji[] znaczek = new KlatkiAnimacji[3];
    public static KlatkiAnimacji background;

    public static AudioClip tickS, dieS;
    public static final int SCIANA_ILE = 9;
	
    private static void wczytaj(Component k) {
        for (int a = 0; a<3; ++a)
        {
            int ile = a<2 ? 2 : SCIANA_ILE;
            znaczek[a] = new KlatkiAnimacji("rzecz"+(a+1)+"/znaczek", ile, ".png", k);
        }
        background = new KlatkiAnimacji("pustynia", 1, ".png", k);

        //dzwieki
        tickS = Utils.wczytajDzwiek("tick.wav");
        dieS = Utils.wczytajDzwiek("die.wav");
    }
    
    public Zasoby() {
        wczytaj(com.gralib.Main.mainFrame);
    }
}
