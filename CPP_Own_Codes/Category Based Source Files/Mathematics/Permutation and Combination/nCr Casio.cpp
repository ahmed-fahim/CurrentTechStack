#include <bits/stdc++.h>
using namespace std;
#define li long long int
#define rl(n) scanf("%I64d", &n)
#define rll(m,n) scanf("%I64d %I64d", &m, &n)
#define rlll(m,n,o) scanf("%I64d %I64d %I64d", &m, &n, &o)
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
#define lim 1e250

map<double, string> converter;
string make_string(double a)
{
    if(a == INFINITY) return "inf";
    if(a == -1) return "MATH ERROR";
    string ret = converter[a];
    if(ret != "") return ret;

    string num;  int dig;char c;
    while(1)
    {
        if(1.00 > a)
        {
            if((int) a == 0) break;
        }
        double div = floor(a/10.00);
        div*=10.00;
        dig = a-div;
        c = char(dig+48);
        a = a/10.0;

        if(c >= 48 && c <= 57)
        {
            num.insert(num.begin()+0,c);
        }
        else{
            num.insert(num.begin()+0, 48);
        }
    }
    return num;
}

map<pair<double, double>, double> presult;
double nPr(double n, double r)
{
    if((li) r > 100000000) return INFINITY;
    if(r > n) return -1;
    if(r < 0.01 || n < 0.01) return -1;
    double m = 1;
    if(presult[mp(n,r)] != NULL)
    {
        return presult[mp(n,r)];
    }

    for(int i= 0; i < r && m != INFINITY; i++)
    {
        m = m*(n-i);
    }
    return presult[mp(n,r)] = m;
}


map<pair<double, double>, double> cresult;
double nCr(double n, double r)
{
    if((li) r > 100000000) return INFINITY;
    if(r > n) return -1;
    if(r < 0.01 || n < 0.01) return -1;
    double m = 1;
    if(cresult[mp(n,r)] != NULL)
    {
        return cresult[mp(n,r)];
    }

    for(int i= 0; i < r && m != INFINITY; i++)
    {
        m = m*((n-i)/(i+1));
    }
    return cresult[mp(n,r)] = m;
}




int main()
{
    int dec; double n,r;
    while(scanf("%lf %lf",&n, &r) != EOF)
    {
        cout<<"n = "<<n<<" :: r = "<<r<< "; nCr = ";
        ri(dec);
        if(dec == 1)
        {
            cout<<make_string(nCr(n,r))<<endl;
        }
        else if(dec == 2)
        {
            n = nCr(n,r);
            if(n == -1) Pr("MATH ERROR\n");
            else cout<<n<<endl;

        }
        Pr("\n");
    }
}
