/*DP hasn't been implimented on this yet, it's just a basic form*/
#include <bits/stdc++.h>
using namespace std;

int coin[] = {1,2,5,10,20,50,100,500};

int main()
{
    int n ,c = 0,indx = -1;
    cout<<"Money to make: ";
    cin>>n;
    int given = 0;

    while(n > 0)
    {
        indx = 7;
        for(int i = indx; i >= 0; i--)
        {
            if(n >= coin[i])
            {
                int num_of_notes = (int) n/(coin[i]);
                given+=num_of_notes * coin[i];
                c+=num_of_notes;
                n-=num_of_notes*coin[i];
                indx = i;
                break;
            }
            else if(i == 0)
            {
                given+=coin[0];
                c+=1;
                n = 0;
                break;
            }
        }
    }

    cout <<"Minimum coin: "<<c<<" given money: " << given<<endl;

}
