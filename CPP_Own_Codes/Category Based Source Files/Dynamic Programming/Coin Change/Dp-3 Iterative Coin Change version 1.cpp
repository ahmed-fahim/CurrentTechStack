/*To find out how many ways a value can be made from some given coins using each coin infinite amount of times*/
#include <bits/stdc++.h>
using namespace std;


int dp[10000];
vector <int> coins;

int main()
{
    coins.push_back(2);
    coins.push_back(3);
    coins.push_back(8);

    int value;
    printf("Highest possible value: ");
    scanf("%d", &value);


    dp[0] = 1;
    for(int i = 0; i  < coins.size(); i++)
    {
        for(int j = coins[i]; j <= value; j++)
        {
            dp[j]+=dp[j-coins[i]];
        }
    }

    cout <<value <<" can be made in "<< dp[value]<<" ways\n";

}
