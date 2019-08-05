/*Testing Divisibility of BIGINTEGERS USING INTEGER */
#include <bits/stdc++.h>
using namespace std;
#define li long long int

int main()
{
    string integer;
    int T;
    li mod;
    scanf("%d ", &T);
    for(int t = 1; t <= T; t++)
    {
        cin>>integer; scanf("%lld", &mod);
        li res = 0;
        if(integer[0] >= '0' && integer[0] <= '9')
        {
            for(int i = 0; i < integer.size(); i++)
            {
                res = (res*10 + (integer[i] -  48)) % mod;
            }
        }
        else{
            for(int i = 1; i < integer.size(); i++)
            {
                res = (res*10 + (integer[i] -  48)) % mod;
            }
        }
        if(res == 0)
        {
            printf("Case %d: divisible\n", t);
        }
        else{
            printf("Case %d: not divisible\n", t);
        }
    }
    return 0;
}
