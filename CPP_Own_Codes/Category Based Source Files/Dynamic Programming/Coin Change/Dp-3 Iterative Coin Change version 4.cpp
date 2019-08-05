/*UVA- 11517, EXACT CHANGE*/
/*
EXPLANATION:

Use Dynamic Programming to determine whether there is a way to make a value V from the n bills.

Let dp[X] be the number of bills needed to make a value of X.

To fill in this DP table, first set dp[0] = 0 and set the rest to INFINITY.

For each bill with value C, update dp[v+C] = min(dp[v+C], dp[v]+1) for all value v where dp[v] is not INFINITY.

The answer is X and dp[X], where X >= P and dp[X] is not INFINITY and X is minimum. To find such X, a simple iteration will do.

PSEUDOCODE:

int dp[30001];

dp[0] = 0;
for (int i=1; i<=30000; i++)
    dp[i] = INFINITE;

for each coin C do
    for (int v = 30001 - C - 1; v >= 0; v--)
        if (dp[v] < INFINITE)
            dp[v+C] = min(dp[v+C], dp[v]+1);

*/
#include <bits/stdc++.h>
using namespace std;
#define INT_MAX 2147483647
#define MAX_POSSIBLE 10000
/*which is equal to 2^31 - 1; largest possible value for signed 32 bit integer*/


int main ()
{
    int testCase,bill,coinNumber, coins[102], dp[MAX_POSSIBLE + 10];
    scanf ("%d", &testCase);

    while ( testCase-- )
    {
        scanf ("%d", &bill);

        scanf ("%d", &coinNumber);

        for ( int i = 0; i < coinNumber; i++ )
        {
                scanf ("%d", &coins [i]);
        }

        for ( int i = 0; i < MAX_POSSIBLE + 10; i++ )
        {
             dp [i] = INT_MAX;
        }

        dp [0] = 0;
        for ( int i = 0; i < coinNumber; i++ )
        {
            /*MAX_POSSIBLE hosse maximum possible value for bill, hence amra MAX_POSSIBLE porjonto dp table ready korbo*/
            for (int j = MAX_POSSIBLE; j >= 0; j-- )
            {
                /*initially loop ta analyze korle dekha jabe,
                when i == 0; only j = 0 er time e eshe she dekhbe
                dp[j] = dp[0] = 0;  whjch is != INT_MAX, && if 0+ coins[i] <= MAX_POSSIBLE &&
                as all other dp[j] except dp[0] will be INT_MAX then,
                hence, dp[j + coins[i]] > dp[0] + 1, so tokhon for the first time
                dp table e value assigned hobe je
                **dp[j+coins[i]] = dp[j] + 1;
                jeitar mane hoilo je (j + coins[i] ) taka banaite, amar j banaite joto gula coin lagto
                tar theke just 1 ta coin beshi lagbe, taholei kono target value er jonno minimum number of coins ber kora jabe
                dp[target] er theke
                */
                if ( dp [j] != INT_MAX && j + coins [i] <= MAX_POSSIBLE )
                {
                    dp [j + coins [i]] = min(( dp [j] + 1 ), dp [j + coins [i]]) ;
                }
            }
        }

        /*eitar mane hosse bill ba bill er closest greater value jeitar jonno minimun number of notes/coins
        use kore value banaite amra jani oi value ta amra oi dp[bill/closest value] ta coin diye pay korbo*/
        for ( int i = bill; i <= MAX_POSSIBLE; i++ )
        {
            if ( dp [i] != INT_MAX )
            {
                printf ("%d %d\n", i, dp [i]);
                break;
            }
        }
        /*jodi kisu print na hoy tar mane hosse oi value er ashe pashe kisu o minimum number of coins diye
        ber kora possible na*/
    }

    return 0;
}

