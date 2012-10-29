package com.gra;

import com.gralib.*;

/**
 *
 * @author pparys
 */
public class Polruch extends PolruchA {
    
    public int e = 0, x[] = new int [3], y[] = new int[3];
    
    public boolean czyCaly() {
        return e==3;
    }
    
    public String zamienNaRuch() {
        return ""+(x[0]+1)+" "+(y[0]+1)+" "+(x[1]+1)+" "+(y[1]+1)+" "+(x[2]+1)+" "+(y[2]+1);
    }
    
    public PolruchA kopiuj() {
        Polruch p = new Polruch();
        p.e = e;
        for (int a = 0; a<3; ++a) {
          p.x[a] = x[a];
          p.y[a] = y[a];
        }
        return p;
    }
}
