/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lovely_lucky_lambs;

import java.util.ArrayList;

/**
 *
 * @author Fahim
 */
public class Solution {

    private final ArrayList<Integer> fibonacciNums, fibonacciSums;
    private final ArrayList<Integer> exponentNums, exponentSums;

    public static int solution(int total_lambs) {
        Solution sol = new Solution();
        return sol.getAbsoluteDiff(total_lambs);
    }

    public Solution() {
        this.fibonacciNums = new ArrayList<Integer>();
        this.fibonacciSums = new ArrayList<Integer>();
        this.exponentNums = new ArrayList<Integer>();
        this.exponentSums = new ArrayList<Integer>();
        this.preCalculateFibonacciSums();
        this.preCalculateExponentSums();
    }

    private int getAbsoluteDiff(int key) {
        int maxFibIndex = getUpperBound(this.fibonacciSums, key);
        int maxExponentIndex = getUpperBound(exponentSums, key);
        //System.out.println(maxFibIndex+" ****** " + maxExponentIndex);
        if (maxFibIndex < 0 && maxExponentIndex < 0) {
            return 0;
        } else if (maxFibIndex < 0) {
            return maxExponentIndex + 1;
        } else if (maxExponentIndex < 0) {
            return maxFibIndex + 1;
        }

        return Math.abs(maxFibIndex - maxExponentIndex);

    }

    private void preCalculateFibonacciSums() {
        this.fibonacciNums.add(1);
        this.fibonacciNums.add(1);
        this.fibonacciSums.add(1);
        this.fibonacciSums.add(2);
        long nextFibNum, nextFibSum;
        for (int i = 2; i < 100; i++) {
            nextFibNum = this.fibonacciNums.get(i - 1) + this.fibonacciNums.get(i - 2);
            if (nextFibNum > 1e9) {
                break;
            }
            this.fibonacciNums.add((int) nextFibNum);

            nextFibSum = this.fibonacciSums.get(i - 1) + this.fibonacciNums.get(i);
            if (nextFibSum > 1e9) {
                break;
            }
            this.fibonacciSums.add((int) nextFibSum);
        }
    }

    private void preCalculateExponentSums() {
        long nextExponentNum = 1;
        long nextExponentSum = 1;
        this.exponentNums.add((int) nextExponentNum);
        this.exponentSums.add((int) nextExponentSum);
        nextExponentNum *= 2;

        for (int i = 1; i <= 30; i++) {
            if (nextExponentNum > 1e9) {
                break;
            }
            this.exponentNums.add((int) nextExponentNum);

            nextExponentSum = nextExponentNum + this.exponentSums.get(i - 1);
            if (nextExponentSum > 1e9) {
                break;
            }
            this.exponentSums.add((int) nextExponentSum);
            nextExponentNum *= 2;
        }
    }

    private int getUpperBound(ArrayList<Integer> arr, int key) {
        int lo = 0;
        int hi = arr.size() - 1;
        int mid;
        int upperBound = -1;

        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (arr.get(mid) == key) {
                upperBound = mid;
                lo = mid + 1;
            } else if (arr.get(mid) < key) {
                lo = mid + 1;
            } else { //key < arr.get(mid)
                hi = mid - 1;
            }
        }
        return upperBound != -1 ? upperBound : hi;
    }

    private int getLowerBound(ArrayList<Integer> arr, int key) {
        int lo = 0;
        int hi = arr.size() - 1;
        int mid;
        int lowerBound = -1;

        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (arr.get(mid) == key) {
                lowerBound = mid;
                hi = mid - 1;
            } else if (arr.get(mid) < key) {
                lo = mid + 1;
            } else { //key < arr.get(mid)
                hi = mid - 1;
            }
        }
        return lowerBound != -1 ? lowerBound : lo;
    }
}
