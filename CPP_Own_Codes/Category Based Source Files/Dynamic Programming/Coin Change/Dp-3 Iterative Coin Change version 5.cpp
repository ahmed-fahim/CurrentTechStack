/*
** Define C[j] to be the minimum number of coins we need to
make change for j cents.
** If we knew that an optimal solution for the problem of
making change for j cents used a coin of traceination di,
we would have:
C[j] = 1+C[j - di].

because, let c[4] banaite di = 2 takar ekta coin use korsi.. hence di taka ta to ekta coin diyei banano jabe.. ar
baki [4-di] taka banaite koyta coin lage eita hishab kora lagbe
*/

#include <bits/stdc++.h>
using namespace std;
#define inf 2147483647

/*Using this We can store all the used coins in vector store. All these coins were used to make the given value "value"*/
void trace_back_all(int *trace, int j, vector <int> *store)
{
    if(j > 0)
    {
        trace_back_all(trace, j - trace[j], store);
        store->push_back(trace[j]);
    }
}


int main()
{
   int value;
   scanf("%d", &value);

    int n; /*Number of coins*/
    scanf("%d", &n);

    int coins[n+1];
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &coins[i]);
    }

    int needed_coins[value+1];
    int trace[value+1]; /*trace[i] would keep trace of the largest coin that was used to make the value i */

    for(int i = 0; i <= value; i++)
    {
        needed_coins[i] = inf;
    }

    needed_coins[0] = 0;

    for(int i = 1; i <= value; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i >= coins[j] && (1 + needed_coins[i - coins[j]] < needed_coins[i]))
            {
                needed_coins[i] = needed_coins[i - coins[j]] + 1;
                trace[i] = coins[j]; /* i value banaite coins[j] use kora hosse shei trace rakha hosse*/
            }
        }
    }

    vector <int> store;
    trace_back_all(trace, value, &store); /*This would trace back for all the coins that were used to make this value */

    cout<<needed_coins[value]<<endl;

    for(int i = 0; i < store.size(); i++)
    {
        cout<<store[i]<<" ";
    }
    cout<<endl;

}
