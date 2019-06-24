/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package prepare_the_bunnies_escape;

import java.util.ArrayList;

/**
 *
 * @author Fahim
 */
class BaseObject<T extends Comparable<T> > extends Number implements Comparable<BaseObject<T> >{
    private T val;
    public BaseObject(){
    }
    public BaseObject(T valArg){
        val = valArg;
    }
    @Override
    public int intValue() {
        if(val instanceof Integer){
            return ((Integer) val).intValue();
        }
        throw new UnsupportedOperationException("Unsupported Type."); 
    }

    @Override
    public long longValue() {
        if(val instanceof Long){
            return ((Long) val).longValue();
        }
        throw new UnsupportedOperationException("Unsupported Type."); 
    }

    @Override
    public float floatValue() {
        if(val instanceof Float){
            return ((Float) val).floatValue();
        }
        throw new UnsupportedOperationException("Unsupported Type."); 
    }

    @Override
    public double doubleValue() {
        if(val instanceof Double){
            return ((Double) val).doubleValue();
        }
        throw new UnsupportedOperationException("Unsupported Type."); 
    }

    @Override
    public int compareTo(BaseObject<T> o) {
        return this.val.compareTo(o.val);
    }
 
}

public class Solution {

    public static int solution(int[][] mapArg) {
        Solution sol = new Solution(mapArg);
        return sol.tryAllCombination();
    }

    private class Cell {

        public int f, s;

        public Cell() {
        }

        public Cell(int fArg, int sArg) {
            f = fArg;
            s = sArg;
        }
    }

    private static final int INFINITY = 10000007;
    private static final int[] DX = {0, 1, 0, -1};
    private static final int[] DY = {1, 0, -1, 0};
    private int[][] map, dist;
    private ArrayList<Cell> Q;
    private int h, w;

    public Solution() {
    }

    public Solution(int[][] mapArg) {
        map = mapArg;
        h = map.length;
        w = map[0].length;
        dist = new int[h][w];
        Q = new ArrayList<Cell>();
        initForBFS();
    }

    private boolean isValid(Cell n) {
        return !(n.f < 0 || n.f >= h || n.s < 0 || n.s >= w);
    }

    private void initForBFS() {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                dist[i][j] = INFINITY;
            }
        }
        Q.clear();
    }

    private int BFS() {
        Cell root = new Cell(0, 0);
        dist[root.f][root.s] = 1;
        Q.add(root);
        while (Q.isEmpty() == false) {
            Cell u = Q.get(0);
            Q.remove(0);
            for (int i = 0; i < 4; i++) {
                Cell v = new Cell(u.f + DY[i], u.s + DX[i]);
                if (!isValid(v)) {
                    continue;
                }

                if (dist[v.f][v.s] > dist[u.f][u.s] + 1 && map[v.f][v.s] == 0) {
                    dist[v.f][v.s] = dist[u.f][u.s] + 1;
                    Q.add(v);
                }
            }
        }
        return dist[h - 1][w - 1];
    }

    private int tryAllCombination() {
        int result = INFINITY;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j] == 1) {
                    map[i][j] = 0;
                    initForBFS();
                    result = Integer.min(BFS(), result);
                    map[i][j] = 1;
                }
            }
        }
        initForBFS();
        result = Integer.min(BFS(), result);
        return result;
    }
}
