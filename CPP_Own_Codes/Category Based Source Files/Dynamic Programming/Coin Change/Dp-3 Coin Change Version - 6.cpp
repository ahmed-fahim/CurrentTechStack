///In how many distinct ways you can make a value N using exactly K coins where no coin is greater
///that Y???
/// ans: In the following code, restricted_partition(N,K,Y) gives the answer.
///Fahim Ahmed :: Dhaka Residential Model College
#pragma comment(linker, "/STACK:16777216") ///Increases Stack size
#include <bits/stdc++.h>
using namespace std;
#define li long long int
///I/O functions begin
#define rfile(a) freopen(a, "r", stdin)
#define wfile(a) freopen(a, "w", stdout)
#define rd(a) scanf("%lf", &a)
#define lb printf("\n")
#define ru(n) scanf("%llu",&n)
#define ruuu(m,n,o) scanf("%llu %llu %llu", &m, &n, &o)
#define ui unsigned long long int
template <typename t1> void wl(t1 x)
{
#ifdef USE_SIGN
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
#endif

    char buf[21], *p = buf;
    do
    {
        *p++ = '0' + x % 10;
        x /= 10;
    }
    while (x);
    do
    {
        putchar(*--p);
    }
    while (p > buf);
}

inline void ri(int &x)
{
    char c;

    while (c = getchar(), c <= ' ');

#ifdef USE_SIGN
    bool sign = c == '-';
    if (sign)
    {
        c = getchar();
    }
#endif

    int res = c - '0';
    while (c = getchar(), c >= '0' && c <= '9')
    {
        res = res * 10 + (c - '0');
    }
    // One character is gobbled here

#ifdef USE_SIGN
    return sign ? -res : res;
#else
    x=res;
#endif
}

inline void rl(long long int &x)
{
    char c;

    while (c = getchar(), c <= ' ');

#ifdef USE_SIGN
    bool sign = c == '-';
    if (sign)
    {
        c = getchar();
    }
#endif

    long long int res = c - '0';
    while (c = getchar(), c >= '0' && c <= '9')
    {
        res = res * 10 + (c - '0');
    }
    // One character is gobbled here

#ifdef USE_SIGN
    return sign ? -res : res;
#else
    x=res;
#endif
}
long long int ctr=0;

bool rs(string *s) //for line input
{
    char buf[200001];
    again:
    if(gets(buf))
    {
        if(buf[0]=='\n' || buf[0] == 0)goto again;
        *s=string(buf);
        return true;
    }
    else return false;
}
bool rtok(string *s) //for input of strings without space
{
    char buf[200001];
    again:
    if(scanf("%s", buf) != EOF)
    {
        if(buf[0]=='\n' || buf[0] == 0 || buf[0]==' ')goto again;
        *s=string(buf);
        return true;
    }
    else return false;
}
///for double,float use scanf
///for printing decimal use wl
///for printing string use puts
///for printing double use printf
///for newline, just type lb;
///I/O functions END
#define pi acos(-1.00)
#define pb push_back
#define mp make_pair
#define Pr printf
#define For(i,a,b) for(int i = a; i < b; i++)
#define MOD 1000003
#define eps 1e-9


typedef long long int ll;
template <typename t1> t1 gcd(t1 a, t1 b) { return b == 0 ? a : gcd(b, a % b); }
template <typename t1> t1 lcm(t1 a, t1 b) { return a * (b / gcd(a, b)); }


li memo[401][21][21];
li restricted_partition(int n, int k, int y)
{
    if(y*k < n)return 0;
    if(n<=0)return 0;
    if(k==1)
    {
        if(y >= n)return 1;
        else return 0;
    }
    if(n<=0 || k<=0 || y <= 0)return 0;
    if(memo[n][k][y] != -1)return memo[n][k][y];

    return memo[n][k][y]=restricted_partition(n,k,y-1) + restricted_partition(n-y, k-1, y);
}
int main()
{
    memset(memo,-1,sizeof(memo));
    li maxx=0;
    for(int x=20; x>=1;x--)
    {
        for(int y=20; y>=1; y--)
        {
            for(int n=x*y; n>=1*x; n--)
            {
                maxx=max(maxx, restricted_partition(n,x,y));
            }
        }
    }
//    cout<<maxx<<endl;

}
