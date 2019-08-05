///Fahim Ahmed :: Dhaka Residential Model College
#pragma comment(linker, "/STACK:16777216") ///Increases Stack size
#include <bits/stdc++.h>
using namespace std;
#define li long long int
#define rl(n) scanf("%I64d", &n)
#define rll(m,n) scanf("%I64d %I64d", &m, &n)
#define rlll(m,n,o) scanf("%I64d %I64d %I64d", &m, &n, &o)
#define ri(n) scanf("%d", &n)
#define rc(n) scanf("%c", &n)
#define rs(n) gets(s)
#define rst(n) getline(cin,n)
#define rfile(a) freopen(a, "r", stdin)
#define pi acos(-1.00)
#define pb push_back
#define mp make_pair
#define Pr printf
#define For(i,a,b) for(int i = a; i < b; i++)
#define MOD 1000003
#define eps 1e-9
#define ru(n) scanf("%llu",&n)
#define ruuu(m,n,o) scanf("%llu %llu %llu", &m, &n, &o)
#define ui unsigned long long int
#define NULL -1

struct edge{
    int u,v,weight;
    edge(){}
    edge(int uu,int vv, int wt)
    {
        u=uu,v=vv,weight=wt;
    }
    void assign(int uu,int vv, int wt)
    {
        u=uu,v=vv,weight=wt;
    }
    bool operator < (const edge& p) const
    {
        return weight < p.weight;
    }
};

struct Basic_Graph
{
    struct node{
        vector <int> adjacent;
        char color;
        int depth;
        int parent;
        int id;
        int discovery,finishing;
        int low;
        node(){}
        node(int val)
        {
            id = val;
        }
        void assign(int val)
        {
            id =val;
        }
        void initialize()
        {
            color= 'w';
            depth = INT_MAX-4;
            parent = NULL;
            low=0;
        }
    };

    node *vertices;
    stack<int> component;
    int node_size;
    int time;
    Basic_Graph()
    {
        node_size = 0;
        //basic constructor;
    }
    Basic_Graph(int n)
    {
        node_size = n;
        vertices = new node[n+1];
    }
    void reset_graph()
    {
        for(int i = 1; i <= node_size; i++)
        {
            vertices[i].initialize();
        }
        time=0;
    }
    void BFS(int source)
    {
        vertices[source].color = 'g';
        vertices[source].depth=0;
        vertices[source].parent = NULL;
        queue<int> Q;
        Q.push(source);
        while(Q.empty() == false)
        {
            int u = Q.front(); Q.pop();
            int sz = vertices[u].adjacent.size();
            for(int i = 0; i < sz; i++)
            {
                int v = vertices[u].adjacent[i];
                if(vertices[v].color == 'w')
                {
                        vertices[v].color = 'g';
                        vertices[v].depth = vertices[u].depth+1;
                        vertices[v].parent = u;
                        Q.push(v);
                }
            }
            vertices[u].color = 'b';
//            printf("%d ",u); //if you want to print BFS traversal
        }
    }
    int BFS_Graph_component(int st)
    {
        reset_graph();
        int components = 0;
        for(int i = st, ct = 1; ct <= node_size; ct++)
        {
            if(vertices[i].color == 'w')
            {
                BFS(i);
                components++;
            }
            i = (i+1)%node_size;
            if(i == 0)i=node_size;
        }
        return components;
    }
    void DFS(int source)
    {
        time++;
        vertices[source].discovery=time;
//        printf("%d ", source); //if you want to print DFS traversal
        vertices[source].color='g';
        int sz = vertices[source].adjacent.size();
        for(int i = 0; i < sz; i++)
        {
            int v = vertices[source].adjacent[i];
            if(vertices[v].color=='w')
            {
                vertices[v].parent = source;
                DFS(v);
            }
        }
        vertices[source].color='b';
        time++;
        vertices[source].finishing=time;
    }
    int DFS_Graph_component(int st)
    {
        reset_graph();
        int components = 0;
        for(int i = st, ct = 1; ct <= node_size; ct++)
        {
            if(vertices[i].color == 'w')
            {
                DFS(i);
                components++;
            }
            i = (i+1)%node_size;
            if(i == 0)i=node_size;
        }
        return components;
    }
    void articulation_points_visit(vector<int> *articulation_points, int source)
    {
        time++;
        vertices[source].discovery=time;
        vertices[source].low=time;
//        printf("%d ", source); //if you want to print DFS traversal
        vertices[source].color='g';
        int sz = vertices[source].adjacent.size();
        int subtree_cntr=0;
        bool added_as_articulation=0;
        for(int i = 0; i < sz; i++)
        {
            int v = vertices[source].adjacent[i];
            if(vertices[v].color=='w')///this is an edge to subtree(u)
            {
                vertices[v].parent = source;
                articulation_points_visit(articulation_points,v);

                //of course the low of parent would be the min of his low and his child's low;
                //and only if his child's low is greater than or equal to his low, then it will prove that
                //he is the root of the subtree, and his children cannot reach to their grand parents
                //without through to their pops
                //but if his child's low is less than his low, that means his child has connection to higher panels

                vertices[source].low=min(vertices[source].low,vertices[v].low);
                subtree_cntr++;
            }
            else{///if v is already visited and u ---> v exists, then it is a backedge
                vertices[source].low=min(vertices[source].low,vertices[v].discovery);
                ///if v.discovery < source.low than it would mean that this is a backedge
                ///that can connect source with it's ancestor v
                ///hence low of source of would be equal to the discovery time of the ancestor he can be connected with
            }
            if(vertices[source].discovery <= vertices[v].low && added_as_articulation == false)
            {
                ///it means that the subtree starting with v cannot get to anyone ancestor of u
                articulation_points->push_back(source);
                added_as_articulation=true;
            }

        }
        if(subtree_cntr > 1 && added_as_articulation == false)
        {
            //if subtree is more than 1, than it is surely to be an articulation point(root of subtrees)
            articulation_points->push_back(source);
            added_as_articulation=true;
        }
        vertices[source].color='b';
        time++;
        vertices[source].finishing=time;
    }
    void articulation_point(vector<int> *articulation_points)
    {
        reset_graph();
        for(int i = 1; i <= node_size; i++)
        {
            if(vertices[i].color == 'w')
            {
                articulation_points_visit(articulation_points,i);
            }
        }
    }

    void tarjan_dfs(int source)
    {
        time++;
        vertices[source].discovery=time;
        vertices[source].low=time;
        component.push(source);
//        printf("%d ", source); //if you want to print DFS traversal
        vertices[source].color='g';
        int sz = vertices[source].adjacent.size();
        int subtree_cntr=0;
        for(int i = 0; i < sz; i++)
        {
            int v = vertices[source].adjacent[i];
            if(vertices[v].color=='w')///this is an edge to subtree(u)
            {
                vertices[v].parent = source;
                tarjan_dfs(v);

                //of course the low of parent would be the min of his low and his child's low;
                //and only if his child's low is greater than or equal to his low, then it will prove that
                //he is the root of the subtree, and his children cannot reach to their grand parents
                //without through to their pops
                //but if his child's low is less than his low, that means his child has connection to higher panels

                vertices[source].low=min(vertices[source].low,vertices[v].low);
                subtree_cntr++;
            }
            else{///if v is already visited and u ---> v exists, then it is a backedge

                vertices[source].low=min(vertices[source].low,vertices[v].discovery);

                ///if v.discovery < source.low than it would mean that this is a backedge
                ///that can connect source with it's ancestor v
                ///hence low of source of would be equal to the discovery time of the ancestor he can be connected with
            }

        }
        if(vertices[source].low == vertices[source].discovery)
        {
            while(component.empty()==false)
            {
                printf("%d ", component.top());
                component.pop();
            }
            printf("\n");
        }
        vertices[source].color='b';
        time++;
        vertices[source].finishing=time;
    }
    int scc_tarjan()
    {
        reset_graph();
        int ctr=0;
        for(int i = 1; i <= node_size; i++)
        {
            if(vertices[i].color == 'w')
            {
                tarjan_dfs(i);
                ctr++;
            }
        }
        return ctr;
    }

};

char _2dgraph[1001][1001];
char _2d_visited[1001][1001];

int main()
{
///Driver for Basic_Graph
//    int n;
//    ri(n);
//    int m;
//    ri(m);
//    Basic_Graph g(n);
//    int u,v,w;
//    for(int i = 1; i <= m; i++)
//    {
//        ri(u); ri(v);
//        g.vertices[u].adjacent.push_back(v);
//        g.vertices[v].adjacent.push_back(u);//do this only for undirected Basic_Graph
//    }
//    printf("total %d components\n", g.DFS_Graph_component(5));
    int n=9;
    int m=7;
    Basic_Graph g(n);
    g.vertices[1].adjacent.push_back(2); g.vertices[2].adjacent.push_back(1);
    g.vertices[2].adjacent.push_back(4); g.vertices[4].adjacent.push_back(2);
    g.vertices[3].adjacent.push_back(2); g.vertices[2].adjacent.push_back(3);
    g.vertices[4].adjacent.push_back(3); g.vertices[3].adjacent.push_back(4);
    g.vertices[4].adjacent.push_back(5); g.vertices[5].adjacent.push_back(4);
    g.vertices[7].adjacent.push_back(8); g.vertices[8].adjacent.push_back(7);
    g.vertices[7].adjacent.push_back(9); g.vertices[9].adjacent.push_back(7);

    int comps=g.scc_tarjan();

}
