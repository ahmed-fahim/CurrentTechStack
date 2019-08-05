///Fahim Ahmed :: Military Institute of Science and Technology
#pragma comment(linker, "/STACK:16777216") ///Increases Stack size
#include <bits/stdtr1c++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//
//using namespace __gnu_pbds;
///// A red-black tree table storing ints and their order
///// statistics. Note that since the tree uses
///// tree_order_statistics_node_update as its update policy, then it
///// includes its methods by_order and order_of_key.
//typedef
//tree<
//  int,
//  null_type,
//  less<int>,
//  rb_tree_tag,
//  // This policy updates nodes' metadata for order statistics.
//  tree_order_statistics_node_update>
//set_t; ///works like set but keeps order
///*
//    extra methods:
//    set_t.find_by_order(order);
//    set_t.order_of_key(key);
//*/
#define li long long int
#define ui unsigned long long int
///I/O functions BEGIN
#define rfile(a) freopen(a, "r", stdin)
#define wfile(a) freopen(a, "w", stdout)
#define rd(a) scanf("%lf", &a)
#define lb printf("\n")
#define ru(n) scanf("%llu",&n)
#define rl(n) scanf("%I64d", &n)
#define ri(n) scanf("%d", &n)
#define rs(n) scanf("%[^\n]",n)
#define rtok(n) scanf("%s",n)
#define MAX_BUFFER_SIZE 200001
#define endl '\n'

///Use printf to output anything
///For string you can also use puts(string.c_str());
///IO functions END
#define pi acos(-1.00)
#define pb push_back
#define mp make_pair
#define Pr printf
#define For(i,a,b) for(int i = a; i < b; i++)
#define MOD 1000003
#define eps 1e-9
#define pii pair<int,int>
template <typename t1> t1 gcd(t1 a, t1 b) {while(b != 0 ){a=a%b;a = a^b;b = b^a;a = a^b;}return a;}
template <typename t1> t1 lcm(t1 a, t1 b) { return a * (b / gcd(a, b)); }
template <typename t1> bool check (t1 i, t1 k){return i&((t1)1<<k);}
template <typename t1> t1 On(t1 i, t1 k) { return i|((t1)1 << k);}
template <typename t1> t1 Off(t1 i, t1 k) {return (i-((check(i,k))<<k) );}

///object Ven Emde Boas Tree
struct vEB{
    int u;
    int min, max;
    int contMin, contMax;
    struct vEB *summary, **cluster;
};


int high(int x, int u){

    return (int)(x/(int)sqrt(u));
}

int low(int x, int u){

    return (x % (int)sqrt(u));
}

vEB* vEB_tree_member(vEB *V, int x){

    if(!V)
        return NULL;
    else if(V->min == x || V->max == x)
        return V;
    else{
        if(V->cluster)
            return vEB_tree_member(V->cluster[high(x, V->u)], low(x, V->u));
        else
            return NULL;
    }
}

int vEB_tree_Minimum(vEB *V){

    return V->min;
}

int vEB_tree_Maximum(vEB *V){

    return V->max;
}

vEB* vEB_tree_insert(vEB *V, int x, int qtd, int u){

    if(!V){
        V = (vEB*)malloc(sizeof(vEB));
        V->min = V->max = x;
        V->u = u;
        V->contMin = V->contMax = qtd;
        if(u > 2){
            V->summary = NULL;
            V->cluster = (vEB**)calloc(sqrt(u),sizeof(vEB*));
        }
        else{
            V->summary = NULL;
            V->cluster = NULL;
        }
    }
    else if(V->min == x){
        V->contMin+=qtd;
        if(V->max == x)
            V->contMax = V->contMin;
    }
    else if(V->max == x){
        V->contMax+=qtd;
    }
    else{
        if(x < V->min){
            if(V->min == V->max){
                V->min = x;
                V->contMin = qtd;
                return V;
            }
            int aux = V->min;
            V->min = x;
            x = aux;
            int qtdAux = V->contMin;
            V->contMin = qtd;
            qtd = qtdAux;
        }
        else if(x > V->max){
            int aux = V->max;
            V->max = x;
            x = aux;
            int qtdAux = V->contMax;
            V->contMax = qtd;
            qtd = qtdAux;
            if(V->min == x)
                return V;
        }
        if(V->u > 2){
            if(V->cluster[high(x, V->u)] == NULL){
                V->summary = vEB_tree_insert(V->summary, high(x, V->u), 1, sqrt(V->u));
            }
            V->cluster[high(x, V->u)] =
            vEB_tree_insert(V->cluster[high(x, V->u)], low(x, V->u), qtd, sqrt(V->u));
        }
    }
    return V;
}

vEB* vEB_tree_delete(vEB *V, int x, int u){
    if(V->min == V->max){
        if(V->contMin > 1){
            V->contMin--;
            V->contMax--;
        }
        else{
            free(V);
            return NULL;
        }
    }
    else if(V->u == 2){
        if(x == 0){
            if(!--V->contMin){
                V->min = 1;
                V->contMin = V->contMax;
            }
        }
        else{
            if(!--V->contMax){
                V->max = 0;
                V->contMax = V->contMin;
            }
        }
    }
    else{
        if(x == V->min){
            if(!--V->contMin){
                if(V->summary){
                    int first_cluster = vEB_tree_Minimum(V->summary);
                    int new_min = vEB_tree_Minimum(V->cluster[first_cluster]);
                    V->min = first_cluster * (int)sqrt(V->u) + new_min;
                    V->contMin = V->cluster[first_cluster]->contMin;
                    (V->cluster[first_cluster])->contMin = 1;
                    if((V->cluster[first_cluster])->min == (V->cluster[first_cluster])->max)
                        (V->cluster[first_cluster])->contMax = 1;
                    V->cluster[first_cluster] = vEB_tree_delete(V->cluster[first_cluster], new_min, sqrt(V->u));
                    if(V->cluster[first_cluster] == NULL)
                        V->summary = vEB_tree_delete(V->summary, first_cluster, sqrt(V->u));
                }
                else{
                    V->min = V->max;
                    V->contMin = V->contMax;
                }
            }
        }
        else if(x == V->max){
            if(!--V->contMax){
                if(V->summary){
                    int last_cluster = vEB_tree_Maximum(V->summary);
                    int new_max = vEB_tree_Maximum(V->cluster[last_cluster]);
                    V->max = last_cluster * (int)sqrt(V->u) + new_max;
                    V->contMax = V->cluster[last_cluster]->contMax;
                    (V->cluster[last_cluster])->contMax = 1;
                    if((V->cluster[last_cluster])->min == (V->cluster[last_cluster])->max)
                        (V->cluster[last_cluster])->contMin = 1;
                    V->cluster[last_cluster] = vEB_tree_delete(V->cluster[last_cluster], new_max, sqrt(V->u));
                    if(V->cluster[last_cluster] == NULL)
                        V->summary = vEB_tree_delete(V->summary, last_cluster, sqrt(V->u));
                }
            }
        }
        else{
            V->cluster[high(x, V->u)] = vEB_tree_delete(V->cluster[high(x, V->u)], low(x, V->u), sqrt(V->u));
            if(V->cluster[high(x, V->u)] == NULL)
                V->summary = vEB_tree_delete(V->summary, high(x, V->u), sqrt(V->u));
        }
    }
    return V;
}

void vEB_tree_print(vEB *V){
    if(V){
        printf("min: %d\tmax: %d\tu: %d\tsummary: %p\tcontMin: %d\tcontMax: %d\n",
         V->min, V->max, V->u, V->summary, V->contMin, V->contMax);
        //puts("<summary>");
        //vEB_tree_print(V->summary);
        //puts("<\\summary>");
        if(V->cluster){
            if(V->cluster){
                int i=0;
                printf("cluster: ");
                for(i = 0; i < sqrt(V->u); i++){
                    printf("%d:%p\t", i, V->cluster[i]);
                }
                printf("\n");
            }
            else{
                printf("cluster: 0\n");
            }
            int i, tam = sqrt(V->u);
            for(i = 0; i < tam; i++){
                vEB_tree_print(V->cluster[i]);
            }
        }
    }
}

void vEB_tree_print_number(vEB *V){
    if(V){
        printf("min: %d\n", V->min);
        if(V->u == 2){
            if(V->min != V->max)
                printf("max: %d\n", V->max);
        }
        if(V->cluster){
            int i, tam = sqrt(V->u);
            for(i = 0; i < tam; i++){
                vEB_tree_print_number(V->cluster[i]);
            }
        }
    }
}

int vEB_tree_elements(vEB *V, int x){

    if(!V)
        return 0;
    else if(V->min == x)
        return V->contMin;
    else if(V->max == x)
        return V->contMax;
    else{
        if(V->cluster)
            return vEB_tree_elements(V->cluster[high(x, V->u)], low(x, V->u));
        else
            return 0;
    }
}


int main(){
    int u = 16;
    vEB *V = NULL;

    V = vEB_tree_insert(V, 5, 1, u);
    V = vEB_tree_insert(V, 1, 4, u);
    V = vEB_tree_insert(V, 6, 1, u);

    printf("there are %d elements 0\n", vEB_tree_elements(V, 0));
    printf("there are %d elements 1\n", vEB_tree_elements(V, 1));
    printf("there are %d elements 2\n", vEB_tree_elements(V, 2));
    printf("there are %d elements 3\n\n", vEB_tree_elements(V, 3));

    V = vEB_tree_delete(V, 1, u);
    V = vEB_tree_delete(V, 5, u);
    V = vEB_tree_delete(V, 6, u);

    printf("there are %d elements 0\n", vEB_tree_elements(V, 0));
    printf("there are %d elements 1\n", vEB_tree_elements(V, 1));
    printf("there are %d elements 2\n", vEB_tree_elements(V, 2));
    printf("there are %d elements 3\n\n", vEB_tree_elements(V, 3));
    vEB_tree_print(V);
    return 0;
}
