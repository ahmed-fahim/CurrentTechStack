#include <iostream>
#include <cmath>

using namespace std;
#define MOD 1000000007


/* algorithm of (a^p) % m */
long long int BigMod(long long int a, long long int P, long long int M)
{
    /* (a^0) % m = 1 */
    if(P==0)
    {
        return 1;
    }

    /* a^8 = a^4 * a^4 => hence (a^8) % m = (((a^4)%m) * ((a^4) % m)) % m */
    if(P%2==0)
    {
        return ((BigMod(a, P/2,M)%M) * (BigMod(a, P/2,M)%M)) % M;
    }

    /*(a^9) % m = (a^8 * a)%m = ((a^8)%m * (a)%m) % m*/
    else
    {
        return (BigMod(a,P-1,M) * (a % M)) % M;
    }

}

/*BIGMOD version 2*/
li bigmod_2(li a, li b)
{
    if(b == 0) return 1 % MOD;
    li x = bigmod_2(a, b/2);
    x = (x * x)%MOD;
    if(b % 2 == 1)x = (x * a) % MOD;
    return x;
}

int main()
{
    long long int a,p,m;

    cout<<"Please Input the values of a,P and M to determine the value of (a ^ P) % M"<<endl<<endl<<"a = ";
    cin>>a;
    cout<<"P = ";
    cin>>p;
    cout<<"M = ";
    cin>>m;

    long long int mod = BigMod(a,p,m);
    cout<<"The mod result is = "<<mod;
    return 0;
}
