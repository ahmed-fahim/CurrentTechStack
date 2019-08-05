#include <bits/stdc++.h>
using namespace std;
#define inf 2147483647

struct edge{
    int u,v,cost;

    bool operator < (const edge& p) const
    {
        return cost < p.cost;
    }
};

struct node
{
    int id;
    int parent;
    int key;

    bool operator < (const node& p) const
    {
        return key > p.key;
    }

    vector <edge> adjacent;
};

int n,e;
node vers[51];

int MST(int r)
{
    for(int i = 1; i <= n ; i++)
    {
        vers[i].key = inf;
        vers[i].parent = -1;
    }
    int total = 0;
    vector<int> extracted(51, 0);
    vers[r].key = 0;
    priority_queue <node> Q;
    for(int i = 1; i <= n; i++)
    {
        Q.push(vers[i]);
    }
    while(!Q.empty())
    {
        node u = Q.top();
        Q.pop();
        extracted[u.id] = 1;

        sort(u.adjacent.begin(), u.adjacent.end());
        for(int i = 0; i < u.adjacent.size(); i++)
        {
            edge e = u.adjacent[i];
            if(extracted[e.v] == 0 && e.cost  < vers[e.v].key)
            {
                if(vers[e.v].parent != -1)
                {
                    total-=vers[e.v].key;
                }
                total+= e.cost;
                vers[e.v].parent = u.id;
                vers[e.v].key = e.cost;
            }
        }
    }
    return total;
}


int main()
{
    freopen("in.txt", "r", stdin);
    cin >> n;
    int r;
    cin >> r;
    cin >> e;
    for(int i = 1; i <= e ; i++)
    {
        edge e1,e2;
        cin >> e1.u >> e1.v >> e1.cost;
        int a,b;
        b = e2.u = e1.v;
        a = e2.v = e1.u;
        e2.cost = e1.cost;
        vers[a].adjacent.push_back(e1);
        vers[b].adjacent.push_back(e2);
        vers[a].id = a;
        vers[b].id = b;
    }
    cout << MST(r) <<endl;
    int extra; cin >> extra;
    for(int i = 1; i <= extra; i++)
    {
        edge e1,e2;
        cin >> e1.u >> e1.v >> e1.cost;
        int a,b;
        b = e2.u = e1.v;
        a = e2.v = e1.u;
        e2.cost = e1.cost;
        vers[a].adjacent.push_back(e1);
        vers[b].adjacent.push_back(e2);
    }
    cout << MST(r) <<endl;
}
