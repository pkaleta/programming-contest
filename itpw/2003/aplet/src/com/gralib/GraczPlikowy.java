package com.gralib;

import java.io.*;
import com.gralib.utils.*;

/**
 *
 * @author mind, pparys
 */
public final class GraczPlikowy extends GraczA {

    public void wez(RuchListener rl) {
        String s = Main.og.rozgrywka.glownyCzytacz.dajRuch(
            Main.og.rozgrywka.stanOst.numerPoltury);
        if (s!=null && s.length()>0 && s.charAt(0)=='-')
            rl.mamRuch(true, s.substring(1, s.length()-1));
        else
            rl.mamRuch(false, s);
    }

    public void daj(String linia) {}

    public void stop() {}
}
