/*See Shafayet vaiya's lecture to get the idea */
#include <bits/stdc++.h>
using namespace std;

int r,c;

int val[1000][1000];

int memo[10000][1000];


int lcs(int i, int j)
{
    if(i >= r || j >= c || i  < 0 || j < 0) return 0;

    else if(memo[i][j] != -1) return memo[i][j];

    int point_in_this_block = val[i][j];
    int val1 = point_in_this_block + lcs(i+ 1, j);
    int val2 = point_in_this_block + lcs(i+ 1, j+1);
    int val3 = point_in_this_block + lcs(i+1, j-1);

    memo[i][j] = max(val1, max(val2,val3));
    return memo[i][j];
}

int main()
{
    cin >>r >>c;
    memset(memo, -1, sizeof(memo));
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j  < c; j++)
        {
            scanf("%d", &val[i][j]);
        }
    }

    int mx = lcs(0,0);
    cout << mx << endl;
}
