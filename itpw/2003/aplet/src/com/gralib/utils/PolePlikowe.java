package com.gralib.utils;

import javax.swing.*;
import javax.swing.filechooser.FileFilter;
import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.io.File;

/**
 * Komponent zawierajacy nazwe pewnego pliku.
 * @author Rafal Rusin, Pawel Parys
 */

public class PolePlikowe extends JPanel {
    /** Nazwa pliku, ktora mozna pobrac */
    private JTextField nazwa;
    JButton button;

    private ListaNasluchow nasluchy=new ListaNasluchow();

    /**
     * Konstruktor tworzy nowe pole plikowe.
     * @param filter filtr plikow dla danego pola
     */
    public PolePlikowe(final FileFilter filter, final String nazwaPliku) {
        setLayout(new BorderLayout());

        nazwa = new JTextField() {
            public Dimension getPreferredSize() {
                return new Dimension(100,10);
            }
        };
        nazwa.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                nasluchy.odpal();
            }
        });
        nazwa.setText(nazwaPliku);
        add(nazwa);

        button = new JButton("..");
        final JPanel ja = this;
        button.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                JFileChooser chooser = new JFileChooser();
                chooser.setFileFilter(filter);
                File dir = (new File(nazwa.getText())).getParentFile();
                chooser.setCurrentDirectory(dir!=null && dir.exists() ? dir : new File("."));
                int returnVal = chooser.showOpenDialog(ja);
                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    File s = chooser.getSelectedFile();
                    nazwa.setText(s.getPath());
                    nasluchy.odpal();
                }
            }
        });

        add(button,BorderLayout.EAST);
    }

    public void zalaczaj(boolean x)
    {
      button.setEnabled(x);
      nazwa.setEnabled(x);
    }

    public void dodajNasluch(Nasluch n) {
        nasluchy.dodaj(n);
    }

    public void setNazwa(JTextField n) { nazwa=n; }
    public JTextField getNazwa() { return nazwa; }
}
