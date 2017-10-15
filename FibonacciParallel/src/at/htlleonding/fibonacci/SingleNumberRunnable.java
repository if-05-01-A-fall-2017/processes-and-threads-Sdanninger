/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package at.htlleonding.fibonacci;

/**
 *
 * @author simon
 */
public class SingleNumberRunnable implements Runnable{
    public int res;
    int n;
    public SingleNumberRunnable(int n) {
        this.n = n;
    }
    
    @Override
    public void run() {
        res = Fibonacci.getNumberSingle(n);
    }
    
}
