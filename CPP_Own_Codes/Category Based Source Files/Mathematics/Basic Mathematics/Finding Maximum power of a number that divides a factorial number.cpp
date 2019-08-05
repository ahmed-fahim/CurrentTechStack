#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for(int tc = 1; tc <= t; tc++)
    {
        int n,k;
        scanf("%d %d", &n, &k);

        int sum = 0;
        int quotent = n;
        while(quotent > 0)
        {
            sum+=(quotent/k);
            quotent/=k;
        }
        printf("Case %d: %d\n", tc, sum);
    }
}
