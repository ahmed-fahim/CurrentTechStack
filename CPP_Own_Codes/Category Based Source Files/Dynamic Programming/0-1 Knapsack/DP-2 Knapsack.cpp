/*This is a 2 state knapsack problem*/
#include <bits/stdc++.h>
using namespace std;

int knapsack_status[101][1001];
/*dhore nissi maximum weight 1000 er beshi hobe na
ar maximum element  100 tar beshi hobe na */
int capacity;
int cost[101],weight[101];  /*oi 100 ta object er jonno array jetay shobar cost ar weight rakha hobe*/
int total_objcts;

inline int knapsack_calc(int i_to_calc, int w_before_i)
{
    if(i_to_calc > total_objcts)
    {
        return 0;
    }
    else if(knapsack_status[i_to_calc][w_before_i] != -1)
    {
        return knapsack_status[i_to_calc][w_before_i];
    }

    int profit_with_i = 0, profit_without_i = 0;

    /*jodi bag er ager ojon er shathe weight[i] jog korle ta capacity er theke beshi
    na hoy tahole oi obj er price ta profit + or porer bostu (i  +1) add korle profit
    joto hobe oitao profit with i er included*/

    if(w_before_i + weight[i_to_calc] <= capacity)
    {
        profit_with_i = cost[i_to_calc]  + knapsack_calc(i_to_calc + 1, w_before_i+weight[i_to_calc]);
    }
    else
    {
        profit_with_i = 0;
    }

    /*eki shathe amra hishab kortisi oi ith object na niye direct (i+1)th  ta niye dekhbo*/
    profit_without_i = knapsack_calc(i_to_calc+1,w_before_i);

    knapsack_status[i_to_calc][w_before_i] = max(profit_with_i,profit_without_i);
    return knapsack_status[i_to_calc][w_before_i];
}

inline void reset()
{
    for(int i = 0; i < 101; i++)
    {
        for(int j = 0; j < 1001; j++)
        {
            knapsack_status[i][j] = -1;
        }
    }
}

int main()
{
    reset();
    printf("Total objects: ");
    scanf("%d", &total_objcts);
    printf("Max capacity: ");
    scanf("%d", &capacity);
    printf("Cost & Weight:\n");

    for(int i = 1; i <= total_objcts; i++)
    {
        scanf("%d %d", &cost[i], &weight[i]);
    }

    int profit = knapsack_calc(1,0);
    printf("%d is the maximum possible profit\n", profit);
}
