/*lightoj - 1231 : coin change(I)*/
/*N coins would be given that we will be able to use at mose "times[i]" times (i = 1 to N, for all N coins)*/
#include <bits/stdc++.h>
using namespace std;
#define mod 100000007;

int main()
{
    int dp[1005], coin[55], times[55];
    int T, n, value;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++)
    {
        scanf("%d %d", &n, &value);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &coin[i]);
        }
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &times[j]);
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for (int j = 0; j < n; j++)
        {
            for (int i = value; i >= 0; i--)
            {
                for (int k = 1; k <= times[j]; k++)
                {
                    if (i - k*coin[j] >= 0)
                    {
                        dp[i] += dp[i-coin[j]*k];
//                        dp[i]%=mod; ///this was only needed for that lightoj problem, remove this before using it as a template code
                    }
                }
            }
        }
        /*to view the number of ways the other values can be made
        for(int i = 1; i <= value; i++) cout<<i <<" can be made "<<dp[i]<<" ways\n";
        */
        printf("Case %d: %d\n", tc, dp[value]);
    }
    return 0;
}

