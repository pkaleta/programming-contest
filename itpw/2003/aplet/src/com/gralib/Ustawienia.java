package com.gralib;

/**
 *
 * @author pparys
 */
public class Ustawienia {
  
  // Klasy
  public static Class oknoGlowneC = OknoGlowne2P.class; // extends OknoGlowne
  public static Class planszaC = null; // extends Plansza
  public static Class kPlanszaC = null; // extends KPlansza
  public static Class rozgrywkaC = null; // extends Rozgrywka
  public static Class zasobyC = null; // initializes client static data when object created
  public static Class graczMyszC = null; // extends GraczMyszA (if czyGraczMysz)
  public static Class polruchC = null; // extends PolruchA (if czyGraczMysz)
  public static Class initGraczUstC = null; // extends initGraczUstA (may be null)

  // Opcje
  public static int ileGraczy = 2;
  public static boolean wyswietlPunkty = false;
  public static boolean czyGraczMysz = false;
  public static boolean stalaLiczbaTur = false; // jesli true, to bedzie pytanie o liczbe tur
  public static boolean jestDzwiek = false;
  public static boolean jestAnimacja = false;
  public static int domyslnaLiczbaTur = 0; // ma sens, jesli stalaLiczbaTur
  public static int domyslnyCzas = 60;
  public static boolean czyGraczUstawienia = false;

  // Wyglad
  public static String tytulOkna = "";
  public static String nazwyGraczy[] = null;
  public static java.awt.Color kolorZaznaczenia = java.awt.Color.BLACK;
  public static int szerokoscSuwaka = 10; // na ile poltur
  public static int czasKlatkiAnimacji = 1;
  public static int domyslneOpoznienie = 200;
}
