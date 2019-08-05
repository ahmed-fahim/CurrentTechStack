/*This problem illustrates basic LCS algorithm, to see the explanation, view Shafaet - DP 5*/
#include <bits/stdc++.h>
using namespace std;

char a[102],b[102];
int memo[101][101];

int lcs(int i, int j)
{
    if(i < 0 || j < 0) return 0;

    if(memo[i][j] != - 1) return memo[i][j];

    if(a[i] == b[j])
    {
        memo[i][j] = 1 + lcs(i-1, j-1);
        return memo[i][j];
    }
    else{
        memo[i][j] = max(lcs(i-1, j), lcs(i,j-1));
        return memo[i][j];
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int tcase = 0;
    while(1)
    {
        gets(a);
        if(a[0] == '#') break;

        gets(b);
        int lena = strlen(a);
        int lenb = strlen(b);
        tcase++;
        memset(memo, -1, sizeof(memo));
        int longest_common_subsequence = lcs(lena-1, lenb-1);
        printf("Case #%d: you can visit at most %d cities.\n", tcase, longest_common_subsequence);
    }
    return 0;
}
