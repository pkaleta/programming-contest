package com.gra;

import com.gralib.*;

/**
 *
 * @author pparys
 */
public class Ruch extends RuchA {
    int x0, y0, x1, y1, x2, y2;
    
    public Ruch(String rs, int xx0, int yy0, int xx1, int yy1, int xx2, int yy2) {
        super(rs);
        x0 = xx0;
        y0 = yy0;
        x1 = xx1;
        y1 = yy1;
        x2 = xx2;
        y2 = yy2;
    }
}
