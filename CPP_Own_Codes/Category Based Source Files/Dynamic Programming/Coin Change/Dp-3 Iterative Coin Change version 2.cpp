/*To find out how many ways a value can be made from some given coins using each coin JUST ONCE*/
#include <bits/stdc++.h>
using namespace std;

int dp[10000] = {0};
vector <int> coins;

int main()
{
    coins.push_back(5); coins.push_back(1);
    coins.push_back(3); coins.push_back(2);
    int value;
    printf("Highest possible value: ");
    scanf("%d", &value);
    dp[0] = 1;
    for(int i = 0; i  < coins.size(); i++)
    {
        for(int j = value; j >= coins[i]; j--)
        {
            dp[j]+=dp[j-coins[i]];
        }
    }
    cout <<value <<" can be made in "<< dp[value]<<" ways\n";
}
