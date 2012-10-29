package com.gralib;

import java.io.IOException;

/**
 *
 * @author mind, pparys
 */
public abstract class GraczA {
    abstract public void wez(RuchListener al);
    abstract public void daj(String tekst);
    abstract public void stop();
    public boolean czyMyszowy() { return false; }
    public long getCzas() { return -1; } // brak pomiaru - wynik ujemny
}
