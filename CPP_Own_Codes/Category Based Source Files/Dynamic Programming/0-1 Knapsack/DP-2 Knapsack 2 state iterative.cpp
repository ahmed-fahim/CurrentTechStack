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


int p[20][10001], d[20][10001];
int v[20], wt[20], n, W;

void knapsack()
{
    for(int w = 0; w <= W;w++) p[0][w] = 0;

    for(int i = 0; i <= n; i++)
    {
        p[i][0] = 0;
        for(int w = 0; w <= W; w++)
        {
            if(wt[i] <= w)
            {
                if(v[i] + p[i-1][w-wt[i]] > p[i-1][w])
                {
                    /*if taking this ith item would result in more profit
                    than we got without the ith item*/
                    p[i][w] = v[i] + p[i-1][w-wt[i]];
                    d[i][w] = 1;
                }
                else if(v[i] + p[i-1][w-wt[i]] == p[i-1][w])
                {
                    p[i][w] = p[i-1][w];
                    d[i][w] = 2;
                }
                else{
                    p[i][w] = p[i-1][w];
                    d[i][w] = 0;
                }
            }
            else{
                p[i][w] = p[i-1][w];
                d[i][w] = 0;
            }
        }
    }
}

void print_single_solution()
{
    int i = n, w = W;

    while(i > 0 && w > 0)
    {
        if(d[i][w] == 1)
        {
            Pr("%d ", i); i--; w-=wt[i+1];
        }
        else
        {
            i--;
        }
    }
    printf("\n");
}
set<li> keeper;
vector<int> ans;
int solution_counter = 0;
void print_multiple_solution(int i, int j)
{
    if(i <= 0 || j <= 0)
    {
        Pr("Solution %d : ", ++solution_counter);
        int sz = ans.size();
        vector<int> sln;
        for(int q = sz-1; q >= 0; q--)
        {
            Pr("%d ", ans[q]);
//            sln.pb(v[ans[q]]);
        }
//        sort(sln.begin(), sln.end());
//        li mul = 0;
//        for(int q = 0; q < sz; q++)
//        {
//            mul*=10;
//            mul+=sln[q];
//        }
//        keeper.insert(mul);
        Pr("\n");
        return;
    }

    if(d[i][j] == 1)
    {
        ans.push_back(i);
        print_multiple_solution(i-1, j - wt[i]);
        ans.pop_back();
    }
    else if(d[i][j] == 2)
    {
        print_multiple_solution(i-1,j);
        ans.push_back(i);
        print_multiple_solution(i-1, j - wt[i]);
        ans.pop_back();
    }
    else{
        print_multiple_solution(i-1,j);
    }
}


int main()
{
	/*Total Item*/
    ri(n);
    for(int i = 1; i <= n; i++)
    {
        ri(v[i]); ri(wt[i]);
    }
    /*Capacity*/
    ri(W);
    knapsack();
    solution_counter = 0;
    print_multiple_solution(n,W);
    set<li> :: iterator it1;
    for(it1 = keeper.begin(); it1 != keeper.end(); it1++)
    {
        cout<<*it1<<endl;
    }
}

/*
input:
5
10 5
7 3
3 2
2 1
3 2
5

Solution 1 : 1
Solution 2 : 2 3
Solution 3 : 2 5

*/
