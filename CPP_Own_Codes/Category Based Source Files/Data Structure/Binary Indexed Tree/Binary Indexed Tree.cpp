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


class BIT{
    li *tree;
    li n;
public:
    BIT(li N)
    {
        n = N;
        tree = new li[n+1];
        memset(tree,0,sizeof(tree));
    }

    li getsum(li index)
    {
        li sum = 0;
        while(index > 0)
        {
            sum+=tree[index];
            index-=index & (-index);
        }
        return sum;
    }

    void update(li index, li amount)
    {
        while(index <= n)
        {
            tree[index]+=amount;
            index+= index & (-index);
        }
    }
};

int main()
{

    BIT a(10);
    a.update(1,2);
    a.update(5,4);
    li sum = a.getsum(7);
    cout<<sum<<endl;
    return 0;
}

