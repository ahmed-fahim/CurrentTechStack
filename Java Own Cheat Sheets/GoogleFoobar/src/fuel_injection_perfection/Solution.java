/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fuel_injection_perfection;

import java.math.BigInteger;
import java.util.TreeMap;

/**
 *
 * @author Fahim
 */
public class Solution {

    private TreeMap<BigInteger, Integer> memo;
    private static final BigInteger ZERO = BigInteger.ZERO;
    private static final BigInteger ONE = BigInteger.ONE;
    private static final BigInteger TWO = BigInteger.valueOf(2);
    private BigInteger Num;

    private int findReductionCount(BigInteger N) {
//        System.out.println("Found " + N);
        if (N.equals(ONE)) {
            return 0;
        }
//        else{
//           System.out.println("Found " + N + " which is clearly not " + ONE); 
//        }
        
        if (memo.containsKey(N)) {
            return memo.get(N);
        }
//        System.out.println("Crossed " + N);

        int result;

        if ((N.remainder(TWO)).equals(ZERO)) {
            BigInteger N_by_2 = N.divide(TWO);
            result = 1 + findReductionCount(N_by_2);
        } else {
            BigInteger N_minus_1 = N.subtract(ONE);
            BigInteger N_plus_1 = N.add(ONE);
            result = 1 + Integer.min(findReductionCount(N_minus_1), findReductionCount(N_plus_1));
        }
        memo.put(N, result);
        return result;
    }

    private void init() {
        memo = new TreeMap<BigInteger, Integer>();
    }
    
    private int getSolution(){
        return findReductionCount(Num);
    }
    
    public Solution() {
        init();
    }

    public Solution(String nArg) {
        init();
        Num = new BigInteger(nArg);
    }
    
    public static int solution(String x) {
        Solution sol = new Solution(x);
        return sol.getSolution();
    }
}
