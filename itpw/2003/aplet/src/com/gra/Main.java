package com.gra;

import com.gralib.*;

/**
 *
 * @author pparys
 */
public class Main {
    public static void main(String[] args) {
      Ustawienia.tytulOkna = "Betoniarki";
      Ustawienia.czyGraczMysz = true;
      Ustawienia.nazwyGraczy = new String[2];
      Ustawienia.nazwyGraczy[0] = "niebieski";
      Ustawienia.nazwyGraczy[1] = "czerwony";
      Ustawienia.jestDzwiek = true;
      Ustawienia.jestAnimacja = true;
      Ustawienia.planszaC = Plansza.class;
      Ustawienia.kPlanszaC = KPlansza.class;
      Ustawienia.rozgrywkaC = Rozgrywka.class;
      Ustawienia.zasobyC = Zasoby.class;
      Ustawienia.polruchC = Polruch.class;
      Ustawienia.graczMyszC = GraczMysz.class;
      Plansza.SIZE_X = 10;
      Plansza.SIZE_Y = 10;
      com.gralib.Main.startAplet();
    }
}
