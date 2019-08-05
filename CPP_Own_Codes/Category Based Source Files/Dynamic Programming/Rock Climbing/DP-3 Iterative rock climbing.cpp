/*See Shafayet vaiya's lecture to get the idea */
#include <bits/stdc++.h>
using namespace std;
#define ri(n) scanf("%d",&n)
#define rfile(a) freopen(a, "r", stdin)

int r,c;

int val[1000][1000];

int memo[1000][1000];




int main()
{
    //rfile("in.txt");
    ri(r); ri(c);
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j  < c; j++)
        {
            scanf("%d", &val[i][j]);
        }
    }

    for(int i = r, j = 0; j <= c; j++)
    {
        memo[i][j] = 0;
        val[i][j] = 0;
    }
    for(int i = 0, j = c; i <= r; i++)
    {
        memo[i][j] = 0;
        val[i][j] = 0;
    }

    for(int i = r-1; i >= 0; i--)
    {
        for(int j = c-1; j >=0; j--)
        {
            int point_in_this_block = val[i][j];
            int down = point_in_this_block + memo[i+1][j] ;
            int right_corner= point_in_this_block + memo[i+1][j+1] ;
            int left_corner = 0;
            if(j > 0)
            {
                left_corner = point_in_this_block + memo[i+1][j-1] ;
            }
            memo[i][j] = max( max(right_corner,left_corner), down);
        }
    }
//
//    for(int i = 0; i < r; i++)
//    {
//        for(int j = 0; j < c; j++)
//        {
//            cout<<memo[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    printf("MAXIMUM POSSIBLE SCORE IF STARTED FROM [0][0] cell is = %d\n", memo[0][0]);

}

/*

test case
3 3
-1 2 5
4 -2 3
1 2 10
*/

