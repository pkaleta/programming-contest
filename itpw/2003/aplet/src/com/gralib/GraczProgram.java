package com.gralib;

import java.io.*;
import com.gralib.utils.Utils;
import javax.swing.*;
import java.awt.event.*;

/**
 *
 * @author mind, pparys
 */
public class GraczProgram extends GraczA {
    private Process proces;
    private BufferedReader rd;
    private PrintWriter wt;
    private long czas = 0;
    private Timer timer;

    public GraczProgram(String nazwaGracza) throws IOException {
        String args[] = new String[1];
        args[0] = nazwaGracza;
        odpal(args);
    }

    public GraczProgram(String[] args) throws IOException {
      odpal(args);
    }

    private void odpal(String[] args) throws IOException {
        proces = Runtime.getRuntime().exec(args);
        rd = new BufferedReader(new InputStreamReader(proces.getInputStream()));
        wt = new PrintWriter(proces.getOutputStream());
        timer = new Timer(0, new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                proces.destroy();
            }
        });
        timer.setCoalesce(false);
        timer.setRepeats(false);
    }

    public void wez(final RuchListener rl) {
        if (getCzas()>1000*KSterowanie.czas) {
            rl.mamRuch(true, "Gracz przekroczyl czas");
            return;
        }
        if (getCzas()>=0) { // dla klas pochodnych (GraczUst) moze nie zachodzic
            timer.setInitialDelay((int)(1000*KSterowanie.czas-getCzas()));
            timer.start();
        }
        final long t0 = System.currentTimeMillis();
        new Thread(new Runnable() {
            public void run() {
                String s = "";
                boolean blad = false;
                try {
                    s = rd.readLine();
                } catch (IOException ex) {
                    blad = true;
                }
                timer.stop();
                czas += System.currentTimeMillis()-t0;
                if (getCzas()>1000*KSterowanie.czas)
                    rl.mamRuch(true, "Gracz przekroczyl czas");
                else
                if (blad)
                    rl.mamRuch(true, "Blad komunikacji z graczem");
                else
                    rl.mamRuch(false, s);
            }
        }).start();
    }

    public void daj(String tekst) {
        wt.print(tekst);
        wt.flush();
    }

    public final void stop() {
        proces.destroy();
        try {
            rd.close();
            wt.close();
        } catch (IOException e) {
            Utils.powiedzWyjatek("Blad przy zamykaniu komunikacji", e);
        }
    }
    
    public long getCzas() {
      return czas;
    }
}
