/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shell;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;

/**
 *
 * @author simon
 */
public class CmdRunnableProcess implements Runnable{
    private String cmd;
    public CmdRunnableProcess(String cmd) {
        this.cmd = cmd;
    }

    @Override
    public void run() {
        StringBuilder output = new StringBuilder();
        try {
            Process p =  Runtime.getRuntime().exec(this.cmd);
            p.waitFor();
            InputStream s = p.getInputStream();
            int b = s.read();
            while (b != -1) {
                System.out.print((char)b);
                b = s.read();
            }
        } catch (Exception e) {
        }
       
    }
    
}
