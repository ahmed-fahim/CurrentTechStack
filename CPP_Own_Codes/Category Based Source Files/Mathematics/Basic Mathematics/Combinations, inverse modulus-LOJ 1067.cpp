/*(nCr % MOD) = [ n! * inverse_modulus( ((r! * (n-r!)) % MOD), MOD) ] % MOD*/

#include <bits/stdc++.h>
using namespace std;
#define li long long int
#define MOD 1000003

li facs[1000001];


//li nCk( li n, li k )
//{
//    if (k > n)
//    {
//        return 0;
//    }
//    if (k * 2 > n)
//    {
//        k = n-k;
//    }
//    if (k == 0) return 1;
//
//    li result = n;
//    for( li i = 2; i <= k; ++i ) {
//        result = (result*(n-i+1))/i;
//        result = result%1000003;
//    }
//    return result;
//}

li inv_modulo(li a, li b)
{
	li b0 = b, t, q;
	li x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

void factorial()
{
    li n = 1000000;
    facs[1] = 1;
    facs[0] = 0;
    li fac = 1;
    for(li i = 2; i <= n; i++)
    {
        fac = (fac*i) % MOD;
        facs[i] = fac;
    }
}

int main()
{
    factorial();
    li T,n,k;
    scanf("%lld", &T);
    for(li t = 1; t <= T; t++)
    {
        scanf("%lld %lld", &n, &k);
        if(k == 0)
        {
            printf("Case %lld: 1\n", t);
            continue;
        }

        li a = facs[n];
        li b = (facs[k] * facs[n-k]) % MOD;
        b = inv_modulo(b, MOD);
        a = (a * b) % MOD;
        printf("Case %lld: %lld\n", t, a);
    }
    return 0;
}
