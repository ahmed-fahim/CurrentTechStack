/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package i_love_lance_janic;

/**
 *
 * @author Fahim
 */
public class Solution {

    public static String solution(String x) {
        StringBuilder resultString = new StringBuilder(x);
        for (int i = 0; i < resultString.length(); i++) {
            if (Character.isLowerCase(resultString.charAt(i))) {
                resultString.setCharAt(i, (char) ((int) 'z' - (int) resultString.charAt(i) + (int) 'a'));
            }

        }
        return resultString.toString();
    }
}
