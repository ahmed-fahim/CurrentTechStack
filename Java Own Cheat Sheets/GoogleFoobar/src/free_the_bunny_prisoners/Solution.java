/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package free_the_bunny_prisoners;

import java.util.ArrayList;

/**
 *
 * @author Fahim
 */
public class Solution {
    private static final int MX = 10;
    private int[][] nCr_memo;
    private boolean[][][] combinationMemo;
    private ArrayList<ArrayList<Integer>>[][][] combinationCollection;

    public static int[][] solution(int n, int r) {
        Solution sol = new Solution();
        

        
        ArrayList<ArrayList<Integer>> allCombinations = sol.generateCombinations(0, n, n - r + 1);
//        System.out.println(allCombinations);

        int totalKeyCount = (int) (sol.nCr(n, r) * r) / (n - r + 1);

        ArrayList<ArrayList<Integer>> retArrList = new ArrayList<>(); 
        for (int i = 0; i < n; i++) {
            ArrayList<Integer> arrListInstance = new ArrayList<>();
            retArrList.add(arrListInstance);
        }
        
        for (int i = 0; i < totalKeyCount; i++) {
            for (int j : allCombinations.get(i)) {
                retArrList.get(j).add(i);
            }
        }
//        System.out.println(retArrList);
        int[][] retVal = new int[n][];
        for (int i = 0; i < retArrList.size(); i++) {
            retVal[i] = new int[retArrList.get(i).size()];
            for (int j = 0; j < retArrList.get(i).size(); j++) {
                retVal[i][j] = retArrList.get(i).get(j);
            }
        }
        
        return retVal;
    }

    public Solution() {
        nCr_memo = new int[MX][MX];
        combinationMemo = new boolean[MX][MX][MX];
        combinationCollection = new ArrayList[MX][MX][MX];
        initMemo();
    }

    private void initMemo() {
        for (int i = 0; i < MX; i++) {
            for (int j = 0; j < MX; j++) {
                nCr_memo[i][j] = -1;
                for (int k = 0; k < MX; k++) {
                    combinationMemo[i][j][k] = false;
                }
            }
        }
    }
   
    
    private int nCr(int n, int r) {
        if (r == 1) {
            return n;
        }
        if (r == n) {
            return 1;
        }
        if (nCr_memo[n][r] == -1) {
            nCr_memo[n][r] = nCr(n - 1, r) + nCr(n - 1, r - 1);
        }
        return nCr_memo[n][r];
    }

    private ArrayList< ArrayList<Integer>> generateCombinations(int start, int n, int r) {
        if (combinationMemo[start][n][r] == false) {
            ArrayList< ArrayList<Integer>> ret = new ArrayList<>();
            if (r > 1) {
                for (int i = start; i < n; i++) {
                    ArrayList<ArrayList<Integer>> response = generateCombinations(i + 1, n, r - 1);
                    if (response.size() > 0) {
                        for (ArrayList<Integer> each : response) {
                            if(each.size() > 0){
                                ArrayList<Integer> copyList = new ArrayList<>();
                                copyList.add(i);
                                each.forEach((x) -> {
                                    copyList.add(x);
                                });
                                ret.add(copyList);
                            }
                        }
                    }
                }
            } else if (r == 1) {
                for (int i = start; i < n; i++) {
                    ArrayList<Integer> newArray = new ArrayList<>();
                    newArray.add(i);
                    ret.add(newArray);
                }
            }

            combinationCollection[start][n][r] = ret;
            combinationMemo[start][n][r] = true;
        }else{
//            System.out.println("Memo Rocks");
        }

        return combinationCollection[start][n][r];
    }

}
