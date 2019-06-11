/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ion_flux_relabeling;

/**
 *
 * @author Fahim
 */
public class Solution {

    /**
     * A list to keep preCalculated values of powers of 2
     */
    private final int pws[];

    /**
     * Required Method Implementation
     */
    public static int[] solution(int h, int[] q) {
        Solution sol = new Solution();
        int[] resultArr = new int[q.length];

        for (int i = 0; i < q.length; i++) {
            int currentRoot = sol.getRootOfHeight_h(h);
            resultArr[i] = sol.findParent(currentRoot, h, q[i]);
        }
        return resultArr;
    }

    /**
     * Solution Class Methods
     */
    public Solution() {
        this.pws = new int[32];
        this.preCalcPowers();
    }

    private void preCalcPowers() {
        int currentPower = 1;
        for (int i = 0; i <= 30; i++) {
            this.pws[i] = currentPower;
            currentPower *= 2;
        }
    }

    private int getRootOfHeight_h(int h) {
        return this.pws[h] - 1;
    }

    private int findParent(int node, int height, int key) {
        if (node == key) {
            return -1;
        }

        int leftSubTreeRoot, rightSubTreeRoot, result;

        leftSubTreeRoot = ((node - this.pws[height - 1]) > 0) ? (node - this.pws[height - 1]) : -1;
        rightSubTreeRoot = ((node - 1) > 0) ? (node - 1) : -1;

        if (leftSubTreeRoot != -1 && key <= leftSubTreeRoot) {
            result = findParent(leftSubTreeRoot, height - 1, key);
            if (result == -1) {
                return node;
            } else {
                return result;
            }
        } else if (rightSubTreeRoot != -1 && key > leftSubTreeRoot && key <= rightSubTreeRoot) {
            result = findParent(rightSubTreeRoot, height - 1, key);
            if (result == -1) {
                return node;
            } else {
                return result;
            }
        } else {
            return -1;
        }

    }

}
