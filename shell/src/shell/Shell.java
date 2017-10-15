/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shell;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.omg.CORBA_2_3.portable.InputStream;

/**
 *
 * @author simon
 */
public class Shell {

    /**
     * @param args the command line arguments
     */
    
    private static Thread t;
    protected static Boolean running = false;
    public static void main(String[] args) throws InterruptedException {
        Boolean running = true;
        Scanner scan;
        String input;
        while(running){
                        System.out.print("Cmd:");
            scan = new Scanner(System.in);
            input = scan.nextLine();

            String[] Cmd = input.split("&&");
            String output = "";
            for (int i = 0; i < Cmd.length; i++) {
                //output += UseCmd(Cmd[i]) ;
                if(Cmd[i].contains("exit"))
                    return;
                UseCmd_2(Cmd[i]);
            }
            Thread.sleep(500);
        }
        
    }
    
    private static void UseCmd_2(String arg){
        Runnable r = new CmdRunnableProcess(arg);
        t = new Thread(r);
        t.start();
        
    }
    
    private static String UseCmd(String arg){
        StringBuilder toReturn = new StringBuilder();
        try {
            Process p;
            p = Runtime.getRuntime().exec(arg);
            p.waitFor();
        
        BufferedReader reader = new BufferedReader(new InputStreamReader(p.getInputStream()));
        String line = "";
            while ((line = reader.readLine())!= null) {
                toReturn.append(line + " ");                
            }
        } catch (Exception e) {
        }
       
       return toReturn.toString();
    }
    
}
