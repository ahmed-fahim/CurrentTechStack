#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a = "123";
    vector <string> mm;
    for(int i = 0; i  < a.length(); i++)
    {
        int left = a.length()-i;
        for(int j = left; j >= 1; j--)
        {
            mm.push_back(a.substr(i,j));
        }
    }
    sort(mm.begin(), mm.end());
    vector<string > :: iterator it;

    for(it = mm.begin(); it != mm.end(); it++)
    {
        string temp = *it;
        cout<<temp<<endl;
    }
}
