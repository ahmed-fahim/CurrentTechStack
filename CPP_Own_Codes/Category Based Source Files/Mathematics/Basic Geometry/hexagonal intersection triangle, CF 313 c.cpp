#include <bits/stdc++.h>
using namespace std;

/*
total number of 1 unit triangles among the parallel lines =
(sum of length of 3 consecutive lines picking any one as the first line)^2 - [(first length)^2 + (third length)^2 + (fifth length)^2]
*/
int main()
{
    int a,b,c,d,e,f; cin>>a>>b>>c>>d>>e>>f;
    int ans = (a + b + c) * (a + b + c) - ((a*a) + (c*c) + (e*e));
    cout<<ans<<endl;
}
