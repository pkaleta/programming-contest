package com.gralib;

import java.io.*;
import com.gralib.utils.*;
import java.util.*;

/**
 *
 * @author mind, pparys
 */
public final class GlownyCzytacz {

    String[] ruch;
    int ilePoltur;
    String naglowek;

    public GlownyCzytacz(String plik) throws IOException {
        BufferedReader rd = new BufferedReader(new FileReader(plik));
        naglowek = rd.readLine();
        String s;
        ilePoltur = 0;
        Vector ruchyV = new Vector();
        while ((s = rd.readLine())!=null) {
            ruchyV.add(s);
            ++ilePoltur;
        }
        rd.close();
        
        // zmien vector na tablice
        ruch = new String[ilePoltur];
        for (int a = 0; a<ilePoltur; ++a) {
            ruch[a] = (String)ruchyV.get(a);
        }
    }
    
    String dajRuch(int nrPoltury) {
        return nrPoltury<ilePoltur ? ruch[nrPoltury] : null;
    }
}
