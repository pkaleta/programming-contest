package com.gralib;

import java.io.*;
import com.gralib.utils.Utils;
import java.util.*;

/**
 *
 * @author pparys
 */
public final class GraczUst extends GraczProgram {

    static private String[] genArgs(String nazwaGracza) {
        String args[] = new String[2];
        args[0] = "gracz_ust"+Utils.SL+"gracz_"+Utils.OS+Utils.OS_EXT;
        args[1] = nazwaGracza;
        return args;
    }

    public GraczUst(String nazwaGracza) throws IOException
    {
        super(genArgs(nazwaGracza));
    }
    
    private Vector poczatek = Ustawienia.initGraczUstC!=null ? new Vector() : null;

    public void daj(String tekst) {
        if (poczatek!=null)
            poczatek.add(tekst);
        else
            super.daj(tekst);
    }

    private void inicjuj(String r, RuchListener rl) {
        try {
            final InitGraczUstA ustInit =
                (InitGraczUstA)Main.newInstance(Ustawienia.initGraczUstC);
            super.daj(ustInit.odpowiedz(r)+Utils.EOL);
            for (int a = 0; a<poczatek.size(); ++a)
                super.daj((String)poczatek.elementAt(a));
            poczatek = null;
            wez(rl);
            return;
        } catch (NumberFormatException ex) {
        } catch (NoSuchElementException ex) {
        }
        rl.wykonanoRuch(true, "Blad komunikacji z graczem!!");
    }

    public void wez(final RuchListener rl) {
        if (poczatek==null)
            super.wez(rl);
        else {
            super.wez(new RuchListener() {
                public void wykonanoRuch(boolean b, String r) {
                    if (b)
                        rl.wykonanoRuch(true, r);
                    else
			inicjuj(r, rl);
                }
            });
        }
    }
    
}

