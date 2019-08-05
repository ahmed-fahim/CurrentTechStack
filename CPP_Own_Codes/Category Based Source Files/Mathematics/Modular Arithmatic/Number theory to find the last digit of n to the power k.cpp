/*METHOD TO FIND THE LAST DIGIT of any N^K: For every N^(4*m+1); the last digit of N will be kept as the N^(4*m+1)'s last digit*/
#include <bits/stdc++.h>
using namespace std;
#define li long long int
#define rl(n) scanf("%lld", &n)
#define rll(m,n) scanf("%lld %lld", &m, &n)
#define rlll(m,n,o) scanf("%lld %lld %lld", &m, &n, &o)
#define ri(n) scanf("%d", &n)
#define rc(n) scanf("%c", &n)
#define rs(n) gets(s)
#define rst(n) getline(cin,n)
#define rfile(a) freopen(a, "r", stdin)
#define pi acos(-1.00)
#define pb push_back
#define mp make_pair
#define Pr printf
#define For(i,a,b) for(int i = a; i < b; i++)
#define MOD 1000003
#define eps 1e-9
#define ru(n) scanf("%llu",&n)
#define ruuu(m,n,o) scanf("%llu %llu %llu", &m, &n, &o)
#define ui unsigned long long int

template <typename t1> t1 gcd(t1 a, t1 b) { return b == 0 ? a : gcd(b, a % b); }
template <typename t1> t1 lcm(t1 a, t1 b) { return a * (b / gcd(a, b)); }
template <typename t1> bool check (t1 i, t1 k){return i&((t1)1<<k);}
template <typename t1> t1 On(t1 i, t1 k) { return i|((t1)1 << k);}
template <typename t1> t1 Off(t1 i, t1 k) {return (i-((check(i,k))<<k) );}


li last_digit_of_n_k(li n, li k)
{
        if(k == 0)
        {
            return 1;
        }
        lastdig = n%10;cur = lastdig;
        li m =(li) (k-1)/4;
        m = 4*m + 1;

        li trns;
        if(m != 1) trns = (k%m);
        else trns = k-1;
        for(li i = 1; i <= trns; i++)
        {
            cur = cur*lastdig;
            cur%=10;
        }
        return cur;
}
int t,n,k,lastdig,cur;
int main()
{
    rfile("in.txt");
    freopen("out.txt","w",stdout);
    ri(t);
    For(tc,1,t+1)
    {
        ri(n); ri(k);
        if(k == 0)
        {
            printf("1\n");
            continue;
        }
        lastdig = n%10;cur = lastdig;
        int m =(int) (k-1)/4;
        m = 4*m + 1;

        int trns;
        if(m != 1) trns = (k%m);
        else trns = k-1;
        for(int i = 1; i <= trns; i++)
        {
            cur = cur*lastdig;
            cur%=10;
        }
        printf("%d\n", cur);
    }

}




