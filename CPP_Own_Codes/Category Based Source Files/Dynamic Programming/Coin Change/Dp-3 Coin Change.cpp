/*using these DP technique in 2 ways we can find 2 things.
1. If we can make a certain amount of money with the use of the given coins in coins[] array.
2. In how many ways that money can be made.
3. We can also do another thing, count the minimum number of coins made to make that much money

***see Shafayet vaiya's book to get details.
*/
#include <bits/stdc++.h>
using namespace std;
#define li long long int

int coin[] = {1,1,2,2,3,3,4,4};
int maxcoins = 7;
int memo1[9][300000];
int memo2[9][300000];


int coinchange_if_can_be_made(int ith_coin, int sumbe4)
{
    if(ith_coin > maxcoins)
    {
        if(sumbe4 == 0) return 1;
        else return 0;
    }

    if(memo1[ith_coin][sumbe4] != -1) return memo1[ith_coin][sumbe4];

    int possibility_with_i = 0, possibility_without_i = 0;

    if(sumbe4 - coin[ith_coin] >= 0)
    {
        possibility_with_i = coinchange_if_can_be_made(ith_coin, sumbe4-coin[ith_coin]);
    }

    possibility_without_i = coinchange_if_can_be_made(ith_coin + 1, sumbe4);

    memo1[ith_coin][sumbe4] = max( possibility_with_i, possibility_without_i );

    return memo1[ith_coin][sumbe4];
}

int coinchange_number_of_ways(int ith_coin, int sumbe4)
{
    if(ith_coin > maxcoins)
    {
        if(sumbe4 == 0) return 1;
        else return 0;
    }

    if(memo2[ith_coin][sumbe4] != -1) return memo2[ith_coin][sumbe4];

    int possibility_with_i = 0, possibility_without_i = 0;

    if(sumbe4 - coin[ith_coin] >= 0)
    {
        possibility_with_i = coinchange_number_of_ways(ith_coin, sumbe4-coin[ith_coin]);
    }

    possibility_without_i = coinchange_number_of_ways( (ith_coin + 1), sumbe4);

    memo2[ith_coin][sumbe4] = possibility_with_i + possibility_without_i ;

    return memo2[ith_coin][sumbe4];
}

int main()
{
    memset(memo1, -1, sizeof(memo1));
    memset(memo2, -1, sizeof(memo1));

    int value_to_make;
    while(1)
    {
        scanf("%d", &value_to_make);
        if(value_to_make  <= 0) break;

        int possbile = coinchange_if_can_be_made(0,value_to_make);
        int ways = coinchange_number_of_ways(0, value_to_make);

        if(possbile == 1)
        {
            cout <<value_to_make<<" can be made in "<<ways<<" ways\n";
        }
        else{
            cout<<"Impossible\n";
        }
    }

}


