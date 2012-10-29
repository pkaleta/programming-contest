package com.gralib;

import com.gralib.utils.Utils;

import java.io.*;
import com.gralib.utils.*;
import java.util.Calendar;
import java.util.StringTokenizer;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 *
 * @author mind, pparys
 */
public final class GraczLog extends GraczA {
    private GraczA gracz;
    private PrintWriter inlog,outlog;

    public GraczLog(GraczA g, String nazwaPliku) throws java.io.IOException {
        gracz = g;
        inlog = new PrintWriter(new FileWriter(Utils.LOG+nazwaPliku+"_log.in"));
        outlog = new PrintWriter(new FileWriter(Utils.LOG+nazwaPliku+"_log.out"));
    }


    public void daj(String tekst) {
        inlog.print(tekst);
        inlog.flush();
        gracz.daj(tekst);
    }

    public void wez(final RuchListener al) {
        gracz.wez(new RuchListener() {
            public void wykonanoRuch(boolean blad, String e) {
                if (!blad) {
                    outlog.println(e);
                    outlog.flush();
                }
                al.mamRuch(blad, e);
            }
        });
    }

    public void stop() {
        outlog.close();
        inlog.close();
        gracz.stop();
    }
    
    public boolean czyMyszowy() {
        return gracz.czyMyszowy();
    }
    
    public long getCzas() {
        return gracz.getCzas();
    }

    static PrintWriter log = null;

    static public void startMain(boolean czyLogowac) {
        if (!czyLogowac) {
            log = null;
            return;
        }
        try {
            log = new PrintWriter(new FileWriter(Utils.LOG+"game.log"));
        } catch (IOException e) {
            Utils.powiedzWyjatek(e);
            log = null;
        }
        dajMain(Calendar.getInstance().getTime().toString()+Utils.EOL);
    }

    static public void dajMain(String tekst) {
        if (log!=null) {
            log.print(tekst);
            log.flush();
        }
    }
    
    static public void stopMain() {
        if (log!=null)
            log.close();
    }
}
