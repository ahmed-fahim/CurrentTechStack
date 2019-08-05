///Fahim Ahmed :: Dhaka Residential Model College
#include <bits/stdc++.h>
using namespace std;
#define li long long int
#define rl(n) scanf("%lld", &n)
#define rll(m,n) scanf("%lld %lld", &m, &n)
#define rlll(m,n,o) scanf("%lld %lld %lld", &m, &n, &o)
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
#define mx 1000001

template <typename t1> t1 gcd(t1 a, t1 b) { return b == 0 ? a : gcd(b, a % b); }
template <typename t1> t1 lcm(t1 a, t1 b) { return a * (b / gcd(a, b)); }
template <typename t1> bool check (t1 i, t1 k){return i&((t1)1<<k);}
template <typename t1> t1 On(t1 i, t1 k) { return i|((t1)1 << k);}
template <typename t1> t1 Off(t1 i, t1 k) {return (i-((check(i,k))<<k) );}


///The following is a segment tree for summation of range only.
///Before applying it to anywhere, change it however you like

li A[mx], tree[4*mx], lazy[4*mx];

void build(int node, int start, int fin)
{
    if(start == fin)
    {
        tree[node] = A[start]; // Leaf node will have a single element
        lazy[node] = 0;
    }
    else
    {
        int mid = (start + fin) / 2;

        build(2*node, start, mid);                      // Recurse on the left child

        build(2*node+1, mid+1, fin);                    // Recurse on the right child

        tree[node] = tree[2*node] + tree[2*node+1];     // Internal node will have the sum of both of its children

        lazy[node] = 0;                                 //Initially all Lazy propagation would be equal to zero
    }
}


void update(int n, int b, int e, int idx, li val)
{
    if (b>e || b>idx || e<idx ) return;
    if (b==e) //at leaf node
    {
        tree[n] = val;
        return;
    }

    update( n*2 , b , (b+e)/2 , idx, val );
    update( n*2 + 1 , (b+e)/2 + 1 , e , idx, val );

    //now some change might have been made in either of the child nodes.

    tree[n] = tree[n*2] + tree[n*2 + 1];

}
void updateRange(int node, int start, int fin, int l, int r, li val)
{
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += (fin - start + 1) * lazy[node];    // Update it
        if(start != fin)
        {
            lazy[node*2] += lazy[node];                  // Mark left child as lazy
            lazy[node*2+1] += lazy[node];                // Mark right child as lazy
        }
        lazy[node] = 0;                                  // Reset the current node's lazy as it has been updated already
    }

    if(start > fin or start > r or fin < l)
    {
        return;                                          // Current segment is not within range [l, r]
    }

    if(start >= l and fin <= r)
    {
        tree[node] += (fin - start + 1) * val;          // Segment is fully within range

        if(start != fin) // Not leaf node
        {
            lazy[node*2] += val;                       //  update the lazy propagation value of left child
            lazy[node*2+1] += val;                     //  update the lazy propagation value of right child
        }
        return;
    }
    int mid = (start + fin) / 2;
    updateRange(node*2, start, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 1, mid + 1, fin, l, r, val);   // Updating right child
    tree[node] = tree[node*2] + tree[node*2+1];        // Updating root with max value
}

li queryRange(int node, int start, int fin, int l, li r)
{
    if(start > fin or start > r or fin < l)
    {
        return 0; // Out of range
    }
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += (fin - start + 1) * lazy[node];            // Update it
        if(start != fin)
        {
            lazy[node*2] += lazy[node];         // Mark child as lazy
            lazy[node*2+1] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start >= l and fin <= r)             // Current segment is totally within range [l, r]
        return tree[node];
    int mid = (start + fin) / 2;
    li p1 = queryRange(node*2, start, mid, l, r);         // Query left child
    li p2 = queryRange(node*2 + 1, mid + 1, fin, l, r); // Query right child
    return (p1 + p2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0),cerr.tie(0);
}


