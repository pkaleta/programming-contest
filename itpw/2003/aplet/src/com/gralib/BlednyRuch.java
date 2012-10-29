package com.gralib;

/**
 *
 * @author pparys
 */
public final class BlednyRuch extends RuchA {
    private String blad;
    
    public BlednyRuch(String bl) {
        super(null);
        blad = bl;
    }
    
    public String dajBlad() {
        return blad;
    }
}
