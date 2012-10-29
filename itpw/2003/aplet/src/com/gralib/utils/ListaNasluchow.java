package com.gralib.utils;

import java.util.*;

public class ListaNasluchow {
    public void dodaj(Nasluch n) {
        tab.add(n);
    }

    public void odpal() {
        Iterator it = tab.iterator();
        while (it.hasNext())
            ((Nasluch) it.next()).dzialaj();
    }

    private ArrayList tab = new ArrayList();
}
