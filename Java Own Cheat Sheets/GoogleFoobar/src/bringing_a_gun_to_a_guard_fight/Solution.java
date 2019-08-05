/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package bringing_a_gun_to_a_guard_fight;

import java.util.*;

/**
 *
 * @author Fahim
 */
public class Solution {

    Point captain, guard;
    int sqDist, h, w;
    ArrayList<Point> points;

    public static int solution(int[] dimensions, int[] your_position, int[] guard_position, int distance) {
        Solution sol = new Solution(dimensions, your_position, guard_position, distance);
        return sol.getSolution();
    }

    public Solution(int[] dimensions, int[] your_position, int[] guard_position, int distance) {
        points = new ArrayList<>();
        sqDist = distance * distance;
        w = dimensions[0];
        h = dimensions[1];
        captain = new Point(your_position[0], your_position[1], false);
        guard = new Point(guard_position[0], guard_position[1], true);
    }

    public int getSolution() {
        int result = 0;
        this.filterPoints();
        Collections.sort(points);
        for (int i = 1; i < points.size();) {
            i++;
            Point cur = points.get(i);
            if (cur.isGuard) {
                result++;
            }

            while (i < points.size()
                    && cur.subtract(captain).isSameVectorAs(points.get(i).subtract(captain))) {
                i++;
            }
        }
        return result;
    }

    public void filterPoints() {
        ArrayList<Point> filteredPoints = new ArrayList<>();
        for (Point p : points) {
            if (p.getSquareDistance(captain) <= sqDist) {
                filteredPoints.add(p);
            }
        }
        points = filteredPoints;
    }

    private void generate_row(Point p) {
        points.add(new Point(p));

        for (int x = p.x + 2 * w;; x += 2 * w) {
            Point t = new Point(x, p.y, p.isGuard);
            // if we have gone too far from the captain, break
            if (t.getSquareDistance(captain) > sqDist) {
                break;
            }
            points.add(t);
        }

        for (int x = p.x - 2 * w;; x -= 2 * w) {
            Point t = new Point(x, p.y, p.isGuard);
            if (t.getSquareDistance(captain) > sqDist) {
                break;
            }
            points.add(t);
        }
    }

    private void generate_grid(Point p) {
        generate_row(new Point(p));

        for (int y = p.y + 2 * h;; y += 2 * h) {
            Point t = new Point(p.x, y, p.isGuard);
            if (t.getSquareDistance(captain) > sqDist) {
                break;
            }
            generate_row(t);
        }

        for (int y = p.y - 2 * h;; y -= 2 * h) {
            Point t = new Point(p.x, y, p.isGuard);
            if (t.getSquareDistance(captain) > sqDist) {
                break;
            }
            generate_row(t);
        }
    }

    private void generate(Point p) {
        generate_grid(new Point(p.x, p.y, p.isGuard));
        generate_grid(new Point(-p.x, p.y, p.isGuard));
        generate_grid(new Point(p.x, -p.y, p.isGuard));
        generate_grid(new Point(-p.x, -p.y, p.isGuard));
    }

    class Point implements Comparable<Point> {

        int x, y;
        boolean isGuard;

        public Point(int X, int Y, boolean mIsGuard) {
            x = X;
            y = Y;
            isGuard = mIsGuard;
        }
        public Point(Point p){
            x=p.x; 
            y=p.y; 
            isGuard=p.isGuard;
        }
        @Override
        public int compareTo(Point o) {
            return this.comparePoints(this.subtract(captain), o.subtract(captain));
        }

        private int comparePoints(Point a, Point b) {
            int qa = a.getQuadrantOfPoint();
            int qb = b.getQuadrantOfPoint();
            if (qa != qb) {
                return Integer.compare(qa, qb);
            }
            int crossMult = a.crossMultiply(b);
            if (crossMult != 0) {
                return Integer.compare(0, crossMult);
            }

            if (Math.abs(a.x) != Math.abs(b.x)) {
                return Integer.compare(Math.abs(a.x), Math.abs(b.x));
            }
            return Boolean.compare(a.isGuard, b.isGuard);
        }

        public Point subtract(Point b) {
            return new Point(this.x - b.x, this.y - b.y, this.isGuard);
        }

        public int getSquareDistance(Point b) {
            return (this.x - b.x) * (this.x - b.x)
                    + (this.y - b.y) * (this.y - b.y);
        }

        public int crossMultiply(Point b) {
            return this.x * b.y - this.y * b.x;
        }

        public int getQuadrantOfPoint() {
            if (this.x >= 0) {
                return this.y >= 0 ? 1 : 4;
            } else {
                return this.y >= 0 ? 2 : 3;
            }
        }

        public boolean equalsTo(Point b) {
            return this.x == b.x
                    && this.y == b.y
                    && this.isGuard == b.isGuard;
        }

        public boolean isSameVectorAs(Point b) {
            return (this.getQuadrantOfPoint() == b.getQuadrantOfPoint()
                    && this.crossMultiply(b) == 0);
        }
    }
}
