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

int dijkstra(int r)
{
    //initialization
    for(int i = 1; i <= n ; i++)
    {
        vers[i].key = inf;
        vers[i].parent = -1;
    }

    //total weight of path
    int total = 0;

    //this collects all the nodes that have been extracted, initially for all the nodes, suppose for node 1, if extracted[1] == 0, then it is still not extracted.
    //if extracted[1] == 1 then it has been extracted. to check if node 3 is extracted check if extracted[3] == 1, if it is 0, then it is not extracted
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
            if(e.cost  + vers[u.id].key < vers[e.v].key)
            {
                if(vers[e.v].parent != -1)
                {
                    total-=vers[e.v].key;
                }
                total+= e.cost + vers[u.id].key;
                vers[e.v].parent = u.id;
                vers[e.v].key = e.cost + vers[u.id].key;
            }
        }
    }
    return total;
}


int main()
{
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
    cout <<"Weight of total path = "<< dijkstra(r) <<endl;

}

