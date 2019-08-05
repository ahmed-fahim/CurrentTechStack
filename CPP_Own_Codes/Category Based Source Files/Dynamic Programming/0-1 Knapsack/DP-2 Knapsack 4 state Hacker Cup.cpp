/*4 state knapsack from facebook hacker cup round1 */
#include <bits/stdc++.h>
using namespace std;


int n;
int gc,gf,gp;
int p[25],c[25],f[25];
 /*20 ta maximum menu, proti tay p,c,f er sum at most 1000*/
int p_memo[25][1001],c_memo[25][1001],f_memo[25][1001];
inline void reset()
{
    for(int i = 0; i < 25; i++)
    {
        for(int j = 0; j  <1001; j++)
        {
            p_memo[i][j] = -1;
            c_memo[i][j] = -1;
            f_memo[i][j] = -1;
        }
    }
}

inline int knapsack_calc(int serial, int p_be4, int c_be4, int f_be4)
{
    if(serial > n)
    {
        /*er mane already shob gula set check kora hoye gese, ekhon jodi bag e thaka p_be4 ba
        current protein er weight, carbohydrate er weight ar fat er weight ta gp,gc, gf er equal hoy
        tar mane shob gula set milaye gp,gc,gf milano possible, hence truth value ta hobe 1*/
        if(p_be4 == gp && c_be4 == gc && f_be4 == gf)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    /*jodi prottektar khetrei dekha jay je ei previos weight obosthay ei same serial er khetre
    oi serial er set ta neya jabe ki jabe na ta agei  ekbar decide kora hoisilo
    tahole notun kore hisab na kore table theke value ta niye boshaye dilei hobe*/
    else if(p_memo[serial][p_be4] != -1 && c_memo[serial][c_be4] != -1 && f_memo[serial][f_be4] != -1)
    {
        return p_memo[serial][p_be4];
    }

    /*serial tomo set ta niye ekta truthvalue pabo, na niye porer ta niye arekta truthvalue pabo,
    2 tai hishab korar jonno 2 ta variable nilam*/
    int trthval_with_i = 0, trthval_without_i = 0;

    /*jodi dekhi je knapsack er already thaka weight er sahthe serial tomo set er
    element gula add korle p,c,f 3 tai capacity er moddhe thake tahole amra dekhbo
    eita niye shamne agaile ki truthvalue paowa jay*/
    if(p_be4+p[serial] <= gp && c_be4+c[serial] <= gc && f_be4+f[serial] <= gf)
    {
        trthval_with_i = knapsack_calc(serial+1, p_be4+p[serial], c_be4+c[serial], f_be4+f[serial]);
    }

    /*eki shathe serial tomo set ta na niye er porer set ta niye agaile finally value ta ki ashe amra sheitao
    dekhbo*/
    trthval_without_i = knapsack_calc(serial+1, p_be4, c_be4, f_be4);

    /*final decision hobe obosshoi 2 ta truthvalue er moddhe better ta, mane finally serial tomo ta ke niye
    ba na niye shesh porjonto gp,gc,gf given set theke milano jay kina eitai set kora hobe final_truth
    er value te, ja hobe 2 ta truth value er moddhe maximum ta
    othoba 2 ta truth er moddhe or || korle jei value ta paowa jabe sheita*/
    int final_truth = max(trthval_with_i,trthval_without_i);

    /*ei serial er ei previous weight niye asha set er jonno prapto truth value ta ke amra memo te rekhe dei*/
    p_memo[serial][p_be4] = c_memo[serial][c_be4]=f_memo[serial][f_be4] = final_truth;

    return final_truth;
}

int main()
{
    freopen("DP-2 Knapsack 4 state Hacker Cup input.txt","r",stdin);
    freopen("DP-2 Knapsack 4 state Hacker Cup output.txt", "w", stdout);
    int T,t;
    scanf("%d", &T);
    for(t = 1; t <= T; t++)
    {
        reset();
        scanf("%d %d %d", &gp, &gc, &gf);
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d %d %d", &p[i], &c[i], &f[i]);
        }

        /*amar quarry shuru hosse 1 no. serial er jinish ke niye jokhon p_be4 = 0, c_be4 = 0, f_be4 = 0
        karon ekhono kono bostu e neya hoy nai knapsack e */
        if(knapsack_calc(1,0,0,0) == 1)
        {
        printf("Case #%d: yes\n",t);
        }

        else{
        printf("Case #%d: no\n",t);
        }
    }
    return 0;
}
