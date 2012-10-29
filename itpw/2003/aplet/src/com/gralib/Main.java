package com.gralib;

import com.gralib.utils.*;

import javax.swing.JFrame;
import java.awt.*;

/**
 *
 * @author mind, pparys
 */
public final class Main {
    public static OknoGlowne og;

    //public static Plansza plansza;
	
    public static JFrame mainFrame;
    
    public static Object newInstance(Class c)
    {
        try {
          return c.newInstance();
        }
        catch (InstantiationException ie) {
            Utils.powiedzWyjatek("Main.newInstance: BLAD!!! Porazka przy tworzeniu klasy!\n", ie);
        }
        catch (IllegalAccessException ie) {
            Utils.powiedzWyjatek("Main.newInstance: BLAD!!! Porazka przy tworzeniu klasy!\n", ie);
        }
        return null;
    }

    public static void startAplet() {
        if (Ustawienia.oknoGlowneC==null || Ustawienia.planszaC==null 
            || Ustawienia.kPlanszaC==null || Ustawienia.rozgrywkaC==null 
            || Ustawienia.zasobyC==null 
            || (Ustawienia.czyGraczMysz && Ustawienia.graczMyszC==null)
            || (Ustawienia.czyGraczMysz && Ustawienia.polruchC==null))
            Utils.powiedzBlad("Main.startAplet: BLAD!!! Nie zdefiniowano wymaganych klas!");
        if (!OknoGlowne.class.isAssignableFrom(Ustawienia.oknoGlowneC)
            || !PlanszaA.class.isAssignableFrom(Ustawienia.planszaC)
            || !KPlanszaA.class.isAssignableFrom(Ustawienia.kPlanszaC)
            || !RozgrywkaA.class.isAssignableFrom(Ustawienia.rozgrywkaC)
            || (Ustawienia.czyGraczMysz
                && !GraczMyszA.class.isAssignableFrom(Ustawienia.graczMyszC))
            || (Ustawienia.czyGraczMysz
                && !PolruchA.class.isAssignableFrom(Ustawienia.polruchC))
            || (Ustawienia.initGraczUstC!=null
                && !InitGraczUstA.class.isAssignableFrom(Ustawienia.initGraczUstC)))
            Utils.powiedzBlad("Main.startAplet: BLAD!!! Nieprawidlowo zdefiniowano klasy!");

	mainFrame = new JFrame(Ustawienia.tytulOkna);
        newInstance(Ustawienia.zasobyC);
        og = (OknoGlowne)newInstance(Ustawienia.oknoGlowneC);
        Runtime.getRuntime().addShutdownHook(new Thread() {
            public void run() {
                Main.og.koniecGry();
            }
        });
        og.show();
    }
}
