/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Tester;
//import i_love_lance_janic.Solution;
//import ion_flux_relabeling.Solution;
//import lovely_lucky_lambs.Solution;
import prepare_the_bunnies_escape.Solution;
/**
 *
 * @author Fahim
 */
public class Main {

//    static void Test_i_love_lance_janic(){
//        System.out.println(Solution.solution("Yvzs! I xzm'g yvorvev Lzmxv olhg srh qly zg gsv xlolmb!!"));
//    }
//    static void Test_ion_flux_relabeling(){
//        Solution sol = new Solution();
//        int []testArr = {19, 14, 28};
//        int[] ret = sol.solution(5, testArr);
//        for(int retVal:ret){
//            System.out.println(retVal);
//        }
//    }
//    static void Test_lovely_lucky_lambs() {
//        System.out.println(Solution.solution(1000000000));
//    }
    static void Test_prepare_the_bunnies_escape(){
        int[][] arg = {{0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 1}, {0, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0}};
        int[][] arg2 = {{0, 1, 1, 0}, {0, 0, 0, 1}, {1, 1, 0, 0}, {1, 1, 1, 0}};
        System.out.println(Solution.solution(arg));
    }
    public static void main(String[] args) {
        Test_prepare_the_bunnies_escape();
    }
}
