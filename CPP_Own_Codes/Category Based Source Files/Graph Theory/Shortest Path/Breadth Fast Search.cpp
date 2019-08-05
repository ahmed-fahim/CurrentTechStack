#include <bits/stdc++.h>
using namespace std;
#define INF 2147483647

struct node{
    vector <int> adjacent;
    string color = "white";
    int depth = INF;
    int parent = NULL;
    int value;
};

void BFS(node *vertices, int source)
{
    vertices[source].color = "gray";
    vertices[source].depth = 0;
    queue <int> serial;
    serial.push(source);
    while(serial.empty() == false)
    {
        int u = serial.front();
        serial.pop();
        for(int i = 0; i < vertices[u].adjacent.size(); i++)
        {
            int v = vertices[u].adjacent[i];
            if(vertices[v].color == "white")
            {
                    vertices[v].color = "gray";
                    vertices[v].depth = vertices[u].depth+1;
                    vertices[v].parent = u;
                    serial.push(v);
            }
        }
        vertices[u].color = "black";
        cout<<vertices[u].value<<" ";
    }
    cout<<endl;
}


int main()
{
    int N;
    cout<<"TOTAL NODES = ";
    cin >> N;
    node vertices[N+1];
    int temp,source;
    cout<<"Which node is the root? ";
    cin >>source;
    cout<<"ROOTVALUE ? ";
    cin>>temp;
    vertices[source].value = temp;

    cout<<"PLEASE ENTER THE VALUE FOR THE REST "<<N-1<<" NODES:\n";
    for(int i = 1; i <= N; i++)
    {
        if(i == source) continue;

        int value; cout<<"VALUE for NODE-"<<i<<" : "; cin>>value;
        vertices[i].value = value;
    }

    int e;
    cout<<"TOTAL EDGES = ";
    cin >>e;

    for(int i = 1; i <= e; i++)
    {
        int x,y;
        cout<<"FOR EDGE "<<i<<endl;
        cout<<"BEGINNING NODE: ";
        cin>>x;
        cout<<"ENDING NODE: ";
        cin>>y;
        vertices[x].adjacent.push_back(y);
        vertices[y].adjacent.push_back(x);
    }

    BFS(vertices, source);
    return 0;
}

/*Test-case:
for a tree like this:

                            5
                           / \
                         /     \
                       /         \
                    6              1
                    /\            /\
                 /     \        /    \
              2         3     4       7
            /
          /
        8

              the total nodes = 8;
              root node = 5;
              total edges = 7;
              and edges are between: (5, 6), (5,1), (6,2), (6,3), (1,4), (1,7), (2,8);
              The level wise travarsel for this tree would be: 5 6 1 2 3 4 7 8

*/

