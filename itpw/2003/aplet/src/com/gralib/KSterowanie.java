package com.gralib;

import com.gralib.utils.Utils;

import javax.swing.*;
import javax.swing.event.ChangeListener;
import javax.swing.event.ChangeEvent;
import javax.swing.filechooser.FileFilter;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemListener;
import java.awt.event.ItemEvent;
import java.io.File;

/**
 *
 * @author mind, pparys
 */
public final class KSterowanie extends JPanel {
    private JButton nowa, dalej;
    public static int ileTur, czas, opoznienie;

    private abstract class Pytanie {
        private String opis, sufix;
        private JLabel label;
        
        Pytanie(String opis, String sufix, int v0, final boolean canBeZero) {
            add(label = new JLabel(""));
            this.opis = opis;
            this.sufix = sufix;
            ustawWartosc(v0);
            final JTextField f = new JTextField(""+v0);
            add(f);
            f.addActionListener(new ActionListener() {
                public void actionPerformed(ActionEvent e) {
                    try {
                        int v = Integer.parseInt(f.getText());
                        if (v>0 || (canBeZero && v==0))
                            ustawWartosc(v);
                        else
                            Utils.powiedzBlad("Niepoprawna wartosc");
                    } catch (NumberFormatException ex) {
                        Utils.powiedzBlad("Niepoprawna wartosc");
                    }
                }
            });
        }

        private void ustawWartosc(int v) {
            label.setText(opis+" ("+v+("".equals(sufix) ? "" : " ")+sufix+")");
            setValue(v);
        }
        
        abstract protected void setValue(int v);
    };

    private abstract class Klikacz {
        Klikacz(String text, boolean v0) {
            JCheckBox cb = new JCheckBox(text, v0);
            add(cb);
            setValue(v0);
            cb.addItemListener(new ItemListener() {
                public void itemStateChanged(ItemEvent e) {
                    setValue(e.getStateChange()==ItemEvent.SELECTED);
                }
            });
        }
        
        abstract protected void setValue(boolean v);
    };

    public KSterowanie() {
        int h = 3;
        if (Ustawienia.stalaLiczbaTur) ++h;
        if (Ustawienia.jestDzwiek || Ustawienia.jestAnimacja) ++h;
        setLayout(new GridLayout(h, 2));
        add(nowa = new JButton("Nowa gra"));
        add(dalej = new JButton("Pauza"));

        new Pytanie("Opoznienie", "ms", Ustawienia.domyslneOpoznienie, true) {
            protected void setValue(int v) { opoznienie = v; Main.og.zmienionoOpoznienie(); }
        };
        
        if (Ustawienia.stalaLiczbaTur)
            new Pytanie("Ile tur", "", Ustawienia.domyslnaLiczbaTur, false) {
                protected void setValue(int v) { ileTur = v; }
            };

        new Pytanie("Czas na gre", "s", Ustawienia.domyslnyCzas, false) {
            protected void setValue(int v) { czas = v; }
        };

        if (Ustawienia.jestDzwiek)
            new Klikacz("Uzywaj dzwieku", true) {
                protected void setValue(boolean v) { Main.og.useSound = v; }
            };

        if (Ustawienia.jestAnimacja)
            new Klikacz("Animuj", true) {
                protected void setValue(boolean v) { Main.og.animuj = v; }
            };

        nowa.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                Main.og.nowaGra();
            }
        });
    }

    private ActionListener oldListener = null;
    private void ustawButton1Listener(ActionListener l) {
        if (oldListener!=null) dalej.removeActionListener(oldListener);
        dalej.addActionListener(l);
        oldListener = l;
    }

    private ActionListener pauzaL=new ActionListener() {
        public void actionPerformed(ActionEvent event) {
            Main.og.zapauzuj();
        }
    };

    private ActionListener dalejL = new ActionListener() {
        public void actionPerformed(ActionEvent event) {
            Main.og.odpauzuj();
        }
    };

    public void wylaczPauze() {
        dalej.setEnabled(false);
    }
    
    public void ustawPauze() {
        dalej.setText("Pauza");
        dalej.setEnabled(true);
        ustawButton1Listener(pauzaL);
    }

    public void ustawDalej() {
        dalej.setText("Dalej");
        dalej.setEnabled(true);
        ustawButton1Listener(dalejL);
    }

}
