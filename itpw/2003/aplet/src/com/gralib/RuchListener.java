package com.gralib;

import java.awt.EventQueue;

/**
 *
 * @author pparys
 */

public abstract class RuchListener implements Runnable {
    public abstract void wykonanoRuch(boolean blad, String r);
    
    private String ruch;
    private boolean blad;
    
    public final void run() {
        wykonanoRuch(blad, ruch);
    }
    
    public final void mamRuch(boolean b, String r) {
        ruch = r;
        blad = b;
        if (RozgrywkaA.wstepne)
            run();
        else
            EventQueue.invokeLater(this);
    }
}
