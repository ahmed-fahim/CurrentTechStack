/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package bomb_baby;

import java.math.BigInteger;

/**
 *
 * @author Fahim
 */
public class Solution {

    private BigInteger M, F;
    private static final BigInteger ONE = BigInteger.ONE;
    private static final BigInteger ZERO = BigInteger.ZERO;
    private static final BigInteger MINUS_ONE = new BigInteger("-1");

    public static String solution(String x, String y) {
        Solution sol = new Solution(x, y);
        return sol.getResult();
    }
    
    public Solution() {
    }

    public Solution(String x, String y) {
        M = new BigInteger(x);
        F = new BigInteger(y);
    }

    private BigInteger reverseReplication(BigInteger m, BigInteger f) {
        BigInteger result = ZERO;
        BigInteger q = ZERO, mult;
        
        /**
         * BigInteger this.compareTo(val) This method returns -1, 0 or 1 as this
         * BigInteger is numerically less than, equal to, or greater than val.
         *
        **/
        
        int mComparesZero = m.compareTo(ZERO);
        int fComparesZero = f.compareTo(ZERO);
        int mComparesF = m.compareTo(f);
        boolean isRunning = true;
        
        while (isRunning) {
//            System.out.println("result = " + result + " m = " + m + " f = " + f);
            if (m.equals(ONE) && f.equals(ONE)) {
                isRunning = false;
            } 
            else if (m.equals(ONE)) {
                result = result.add(f.subtract(ONE));
                isRunning = false;
            } 
            else if (f.equals(ONE)) {
                result = result.add(m.subtract(ONE));
                isRunning = false;
            } 
            else if (mComparesZero == -1 || mComparesZero == 0
                    || fComparesZero == -1 || fComparesZero == 0 || mComparesF == 0) 
            {
                result = MINUS_ONE;
                isRunning = false;
            } 
            else {
                switch (mComparesF) {
                    case -1: //m less than f
                        q = f.divide(m);
                        result = result.add(q);
                        mult = q.multiply(m);
                        f = f.subtract(mult);
                        mComparesF = m.compareTo(f);
                        fComparesZero = f.compareTo(ZERO);
                        break;
                    case 1: //m greater than f
                        q = m.divide(f);
                        result = result.add(q);
                        mult = q.multiply(f);
                        m = m.subtract(mult);
                        mComparesF = m.compareTo(f);
                        mComparesZero = m.compareTo(ZERO);
                        break;
                    default:
                        break;
                }
//                System.out.println("q = " + q + " result = " + result + " m = " + m + " f = " + f);
            }
        }
        return result;
    }

    private String getResult() {
        BigInteger res = reverseReplication(M, F);
        if (res.equals(MINUS_ONE)) {
            return "impossible";
        } else {
            return res.toString();
        }
    }
}
