package com.gralib;

/**
 *
 * @author pparys
 */
public abstract class PlanszaA {

    public int selx, sely;
    public boolean selected = false;

    public static int SIZE_X, SIZE_Y;

    abstract public PlanszaA kopiuj();

    // stan poczatkowy
    abstract public void czysc();

    public static boolean naPlanszy(int x, int y) {
        return x >= 0 && x < SIZE_X && y >= 0 && y < SIZE_Y;
    }
    
    // ANIMACJA

    // Animacja moze byc podzielona na etapy (fragmenty ruchu).

    // Gdy trzeba animowac ruch, to zostaje wywolana funkcja animujRuch.
    // Animacja rozpoczyna sie tez przez wywolanie GraczMysz::animujKlik.

    // Funkje te powinny ustawic zmienne animNastepnaKlatka (koniecznie) i
    // animNastepnyEtap (byc moze) oraz wewnetrze dane w planszy, ktore 
    // pozwalaja na wyswietlanie jej w trakcie animacji.  


    // Jak przychodzi czas na nastepna klatke (w tym na pierwsza inna
    // od oryginalu), to wywolywana jest animNastepnaKlatka. Powinna ona
    // przestawic wewnetrze dane planszy na nastepna klatke. Ponadto ma ona ustawic
    // animNastepnaKlatka na null, jesli:
    // - nadchodzaca klatka jest tym co ma byc zawsze po tym etapie
    // - nie ma akurat animacji 
    // Jak zwroci false, to ta plansza nie zostanie wyswietlona, tylko ta po 
    // przejsciu to nastepnego etapu.
    
    // Gdy animNastepnaKlatka==null, to etap jest skonczony, ale jesli
    // jeszcze jest ustawiony animNastepnyEtap, to jest on wywolywany. Ma on
    // dzialac tak jak anumujRuch (przed jego wywolaniem animNastepnyEtap jest
    // ustawiany na null).
    
    public void animujRuch(RuchA ruch) {
    }
    
    protected Runnable animNastepnaKlatka = null;
    protected Runnable animNastepnyEtap = null;
    
    // Przewija na nastepna klatke (w tym na pierwsza inna inna od oryginalu).
    // Powinna zwracac false, gdy trzeba juz wyswietlic stan koncowy, czyli:
    // - nadchodzaca klatka jest tym co ma byc zawsze
    // - gdy nie ma akurat animacji
    // Jak zwroci false, to ta plansza nie zostanie juz wyswietlona, tylko ta po calym ruchu.
    public final boolean nastepnaKlatkaAnimacji() {
        if (animNastepnaKlatka==null) 
            return false;
        animNastepnaKlatka.run();
        while (animNastepnaKlatka==null && animNastepnyEtap!=null) {
            Runnable x = animNastepnyEtap;
            animNastepnyEtap = null;
            x.run();
        }
        return animNastepnaKlatka!=null;
    }
}
