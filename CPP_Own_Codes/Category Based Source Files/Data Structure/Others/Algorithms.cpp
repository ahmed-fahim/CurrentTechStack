/*<algorithm> handling*/
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

int main()
{
        vector<int>V;

        V.push_back(23);
        V.push_back(21);
        V.push_back(53);
        V.push_back(53);
        V.push_back(53);
        V.push_back(59);
        V.push_back(25);
        V.push_back(48);

        //Pre-condition of Binary search is to sort the vector
        sort(V.begin(),V.end());

        for(int i=0;i<V.size();i++)
            cout<<V[i]<<" ";
        cout<<endl;
        if(binary_search(V.begin(),V.end(),53))
            cout<<"Found"<<endl;
        else
            cout<<"Not Found"<<endl;

        if(binary_search(V.begin(),V.end(),10))
            cout<<"Found"<<endl;
        else
            cout<<"Not Found"<<endl;


        //lower bound
        vector<int>::iterator it;

        it=lower_bound(V.begin(),V.end(),55);
        int pos=it-V.begin();
        int indx=pos-1;
        cout<<" Lowe bound of 55 is at position="<<pos<<" "<<V[indx]<<endl;


        //Upper bound
        it=upper_bound(V.begin(),V.end(),50);
        pos=it-V.begin();
        indx=pos-1;
        cout<<"Upper bound of 50 is at position="<<pos<<" "<<V[indx]<<endl;


        //Next permutation
        char arr[] = "ABC";
        do{
            puts(arr);
        }while(next_permutation(arr,arr+3));
        return 0;
}
