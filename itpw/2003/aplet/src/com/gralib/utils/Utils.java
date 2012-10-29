package com.gralib.utils;

import javax.swing.*;
import java.io.File;
import java.applet.AudioClip;
import java.applet.Applet;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.net.URL;

public class Utils {
    public static final String EOL = System.getProperty("line.separator"), SL = File.separator,
    LOG = "log"+SL,
    OS, OS_EXT;

    private static final String RES = "res";

    static {
        String os = System.getProperty("os.name").toLowerCase();
        if (os.indexOf("windows") == -1) {
            OS = "linux";
            OS_EXT = ".e";
        } else {
            OS = "windows";
            OS_EXT = ".exe";
        }
    }

    /** proste okienko dialogowe */
    public static void powiedz(String s) {
        JOptionPane.showMessageDialog(null, s);
    }

    /** okienko do wypisywania na ekran bledow */
    public static void powiedzBlad(String s) {
        JOptionPane.showMessageDialog(null, s, "Blad", JOptionPane.ERROR_MESSAGE);
    }

    public static String exc2str(Exception e) {
        String msg = e.getMessage();
        return (msg != null ? msg + "\n" : "") + "(" + e.getClass().getName() + ")";
    }

    public static void powiedzWyjatek(String s, Exception e) {
        powiedzBlad(s+exc2str(e));
    }

    public static void powiedzWyjatek(Exception e) {
        powiedzWyjatek("", e);
    }

    public static Image createOptimizedImage(ImageIcon image, Component c) {
        Image i = image.getImage();
        ;

        try {
            String version = System.getProperties().getProperty("java.version");
            if (version.substring(0, 3).equals("1.3") || version.substring(0, 3).equals("1.4")) {
                i = new BufferedImage(image.getIconWidth(), image.getIconHeight(), BufferedImage.TYPE_INT_ARGB);
                i.getGraphics().drawImage(image.getImage(), 0, 0, c);
            }
        } catch (java.security.AccessControlException e) {
            e.printStackTrace();
        }
        return i;
    }

    public static URL getResourceUrl(String nazwa) {
            String s="/" + RES + "/" + nazwa;
            URL r=Utils.class.getResource(s);
            return r;
    }

    public static AudioClip wczytajDzwiek(String nazwa) {
        //return Applet.newAudioClip(baza.getClass().getResource(nazwa));
        URL u = getResourceUrl(nazwa);
        AudioClip clip = Applet.newAudioClip(u);
        //if (clip==null) Utils.powiedzBlad("Nie mozna wczytac dzwieku: \""+nazwa+"\"");
        return clip;
    }

}
