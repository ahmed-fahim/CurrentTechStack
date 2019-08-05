#include <bits/stdc++.h>
using namespace std;

bool check (int i, int k)
{
    return (i>>k)&1;
}
int On(int i, int k)
{
    return i|(1 << k);
}
int Off(int i, int k)
{
    return (i-((check(i,k))<<k)  );
}

unsigned status[10000032/32] = {0};

vector<pair<int,int> > prime_factors[1000001];
void siv()
{
    int i, j, sq;
    sq = (int) sqrt(1000000);
    status[0/32] = On(status[0/32], 0%32);
    status[1/32] = On(status[1/32], 1%32);

    for(i = 3; i <= sq; i+=2)
    {
        if(check(status[i/32], i%32) == 0)
        {
            for(j = i * i; j <= 1000000; j+=2*i)
            {
                status[j/32] = On(status[j/32], j % 32);
            }
        }
    }
}

void prime_factorization()
{
    prime_factors[2].push_back({2,1});
    prime_factors[3].push_back({3,1});
    for(int i = 4; i <= 1000000; i++)
    {
        if(check(status[i/32],i%32) == 1 || (i % 2 == 0))
        {
            int sq = sqrt(i);
            for(int j = 2; j <= sq; j++)
            {
                int k = i/j;
                if(k * j == i)
                {
                    int x,y,a,b;
                    x = prime_factors[j].size();
                    y = prime_factors[k].size();

                    for(a = 0, b = 0; a < x || b < y; )
                    {
                        pair<int,int> p1,p2;
                        if(a < x && b < y)
                        {
                            p1 = prime_factors[j][a];
                            p2 = prime_factors[k][b];
                            if(p1.first == p2.first)
                            {
                                p1.second+=p2.second;
                                prime_factors[i].push_back(p1);
                                a++; b++;
                            }
                            else if(p1.first < p2.first)
                            {
                                prime_factors[i].push_back(p1);
                                a++;
                            }
                            else{
                                prime_factors[i].push_back(p2);
                                b++;
                            }
                        }
                        else if(a < x)
                        {
                            prime_factors[i].push_back(prime_factors[j][a++]);
                        }
                        else
                        {
                            prime_factors[i].push_back(prime_factors[k][b++]);
                        }

                    }
                    break;
                }
            }
        }
        else{
            prime_factors[i].push_back({i,1});
        }
    }
}

int main()
{
    siv();
//    cout<<"2 is a prime\n";
//    for(int i = 3; i <= 30; i+=2)
//    {
//        if((check(status[i/32], i % 32) == 0))
//        {
//            cout<<i <<" is a prime\n";
//        }
//    }
    prime_factorization();
//    for(int i = 0; i < prime_factors[18].size(); i++)
//    {
//        cout<<prime_factors[18][i].first<<"^"<<prime_factors[18][i].second<<" ";
//    }
//    cout<<endl;
}
