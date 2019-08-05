#include <bits/stdc++.h>
using namespace std;

///Dynamic programming
///Type: Bottom Up Range Fill
///Complexity: O(n*m + q)

int matrix[1003][1003];
int dp[1003][1003]={0}; ///this one must have row+1 rows and col+1 columns
int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int q;
    scanf("%d", &q);
    int i1[100003], j1[100003], i2[100003], j2[100003], a[100003];
    int n,m;
    for(int qq = 1; qq <= q; qq++)
    {
        scanf("%d %d %d %d %d", &i1[qq], &j1[qq], &i2[qq], &j2[qq], &a[qq]);
    }
    scanf("%d %d", &m, &n);
    for(int i= 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    for(int qq = 1; qq <= q; qq++)
    {
        ///this will be cumulatively added to the cells
        dp[ i1[qq] ][ j1[qq] ]+=a[qq];

        ///this negative value will only be used when the cells have added the a[qq] more than once
        ///or sometimes it might just delete the cell even after being added only once
        ///that will be compensated by the following addition
        dp[ i1[qq] ][ j2[qq] + 1 ] -=a[qq];

        ///this value will have the chance to be added only if this cell hasn't already got the del or
        ///the first del has been nullified by the above negation
        dp[i2[qq] + 1][ j2[qq] + 1 ] +=a[qq];

        ///this negative value will only be used when the cells have added the a[qq] more than once
        dp[i2[qq] + 1][ j1[qq] ] -=a[qq];
    }

    ///bottom - up approach
    ///step-1:
    for(int r = 1; r <= m; r++)
    {
        for(int c = 2; c <= n; c++)
        {
            dp[r][c] += dp[r][c-1];///addition from left column to the right
        }
    }

    ///step-2:
    for(int r = 2; r <= m; r++)
    {
        for(int c = 1; c <= n; c++)
        {
            dp[r][c] += dp[r-1][c];///addition from top row to bottom
        }
    }


    for(int i= 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            matrix[i][j]+=dp[i][j];
            printf("%d", matrix[i][j]);
            if(j < n)printf(" ");
        }
        printf("\n");
    }
    return 0;
}
