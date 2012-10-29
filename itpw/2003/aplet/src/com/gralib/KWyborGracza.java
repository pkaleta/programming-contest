package com.gralib;

import com.gralib.utils.PolePlikowe;
import com.gralib.utils.Utils;

import javax.swing.*;
import javax.swing.text.*;
import javax.swing.filechooser.FileFilter;
import java.awt.*;
import java.io.File;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

/**
 *
 * @author mind, pparys
 */
public final class KWyborGracza extends JPanel {

    private JRadioButton rodzajPlikowy, rodzajProgram, rodzajMysz, rodzajUst;
    public JLabel punkty, czas;
    
    static Document plikZLogami = null;
    Document plikZProgramem, plikZUstawieniami;

    public KWyborGracza() {
        if (plikZLogami==null)
        {
            JTextField tf = new JTextField();
            tf.setText("log"+Utils.SL+"game.log");
            plikZLogami = tf.getDocument();
        }
    
        setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));

        if (Ustawienia.wyswietlPunkty)
            add(punkty = new JLabel(" "));
        add(czas = new JLabel(" "));
        add(new JLabel("Typ zawodnika:"));
        if (Ustawienia.czyGraczUstawienia) {
            add(rodzajUst=new JRadioButton("Plik z ustawieniami", true));
            grupa.add(rodzajUst);
        }
        add(rodzajProgram=new JRadioButton("Program", true));
        grupa.add(rodzajProgram);
        add(rodzajPlikowy=new JRadioButton("Plik z ruchami"));
        grupa.add(rodzajPlikowy);
        if (Ustawienia.czyGraczMysz)
        {
            add(rodzajMysz=new JRadioButton("Mysz"));
            grupa.add(rodzajMysz);
        }
        
        String graczPrDom = "gracze"+Utils.SL+Utils.OS+Utils.SL+"test1"+Utils.OS_EXT;
        String graczUstDom = "ustawienia"+Utils.SL+"domyslne.ust";

        polePlikowe = new PolePlikowe(new FileFilter() {
            private String chceExt() {
                return rodzajPlikowy.isSelected() ? "log" :
                  Utils.OS.equals("linux") ? null : "exe";
            }

            public boolean accept(File f) {
                if (f==null)
                    return false;
                if (chceExt()==null || f.isDirectory())
                    return true;
                String extension = getExtension(f);
                return chceExt().equals(extension);
            }

            private String getExtension(File f) {
                if(f != null) {
                    String filename = f.getName();
                    int i = filename.lastIndexOf('.');
                    if(i>0 && i<filename.length()-1)
                        return filename.substring(i+1).toLowerCase();
                }
                return null;
            }

            public String getDescription() {
                return (rodzajPlikowy.isSelected() ? "Ruchy gracza" : "Program gracza")+
		    (chceExt()!=null ? " (*."+chceExt()+")" : "");
            }
        }, Ustawienia.czyGraczUstawienia ? graczUstDom : graczPrDom);
        add(polePlikowe);

        if (Ustawienia.czyGraczUstawienia) {
            plikZUstawieniami = polePlikowe.getNazwa().getDocument();
            JTextField tf = new JTextField();
            tf.setText(graczPrDom);
            plikZProgramem = tf.getDocument();
        }
        else
            plikZProgramem = polePlikowe.getNazwa().getDocument();

        rodzajProgram.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                polePlikowe.getNazwa().setDocument(plikZProgramem);
            }
        });
        if (Ustawienia.czyGraczUstawienia)
            rodzajUst.addActionListener(new ActionListener() {
                public void actionPerformed(ActionEvent e) {
                    polePlikowe.getNazwa().setDocument(plikZUstawieniami);
                }
            });
        rodzajPlikowy.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                polePlikowe.getNazwa().setDocument(plikZLogami);
            }
        });
        if (Ustawienia.czyGraczMysz)
            rodzajMysz.addActionListener(new ActionListener() {
                public void actionPerformed(ActionEvent e) {
                    polePlikowe.zalaczaj(false);
                }
            });

        ActionListener zalacz = new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                polePlikowe.zalaczaj(true);
            }
        };
        rodzajProgram.addActionListener(zalacz);
        rodzajPlikowy.addActionListener(zalacz);
        if (Ustawienia.czyGraczUstawienia)
            rodzajUst.addActionListener(zalacz);
    }

    public GraczA stworzGracza() throws Exception {
        if (rodzajPlikowy.isSelected())
            return new GraczPlikowy();
        else if (rodzajProgram.isSelected())
            return new GraczProgram(polePlikowe.getNazwa().getText());
        else if (Ustawienia.czyGraczMysz && rodzajMysz.isSelected())
            return (GraczMyszA)Main.newInstance(Ustawienia.graczMyszC);
        else if (Ustawienia.czyGraczUstawienia && rodzajUst.isSelected())
            return new GraczUst(polePlikowe.getNazwa().getText());
        else throw new Exception("Nalezy wybrac rodzaj gracza.");
    }

    private ButtonGroup grupa=new ButtonGroup();

    public void setRodzajPlikowy(JRadioButton b) { rodzajPlikowy=b; }
    public JRadioButton getRodzajPlikowy() { return rodzajPlikowy; }

    public void setRodzajProgram(JRadioButton b) { rodzajProgram=b; }
    public JRadioButton getRodzajProgram() { return rodzajProgram; }

    private PolePlikowe polePlikowe;
    public void setPolePlikowe(PolePlikowe p) { polePlikowe=p; }
    public PolePlikowe getPolePlikowe() { return polePlikowe; }
    
    public boolean czyPlikowy() { return rodzajPlikowy.isSelected(); }

}
