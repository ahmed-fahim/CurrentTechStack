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

template <typename t1> t1 gcd(t1 a, t1 b) { return b == 0 ? a : gcd(b, a % b); }
template <typename t1> t1 lcm(t1 a, t1 b) { return a * (b / gcd(a, b)); }
template <typename t1> bool check (t1 i, t1 k){return i&((t1)1<<k);}
template <typename t1> t1 On(t1 i, t1 k) { return i|((t1)1 << k);}
template <typename t1> t1 Off(t1 i, t1 k) {return (i-((check(i,k))<<k) );}

class Heap
{
    vector<li> arr;
    li length, tail;

    public:
        Heap()
        {
            length = tail = 0;
            arr.pb(0);
        }

        li left(li index)
        {
            return 2*index;
        }
        li right(li index)
        {
            return 2*index + 1;
        }
        void push(li a)
        {
            arr.pb(0);
            length++;
            tail++;
            arr[tail]=a;
        }
        void heapify(li index)
        {
            li l,r;
            l = left(index), r = right(index);
            li largest = index;
            if(l <= tail && arr[l] > arr[index]) largest = l;
            if(r <= tail && arr[r] > arr[largest]) largest = r;

            if(largest != index)
            {
                swap(arr[largest], arr[index]);
                heapify(largest);
            }
        }
        void buildhip()
        {
            for(li i = length/2; i >= 1; i--)
            {
                heapify(i);
            }
        }
        void Heapsort()
        {
            li prevtail = tail;
            this->buildhip();
            for(li i = length; i >= 2; i--)
            {
                swap(arr[1],arr[i]);
                tail--;
                heapify(1);
            }
            tail = prevtail;
        }
        void show()
        {
            for(li i = 1; i <= tail; i++)
            {
                Pr("%lld ", arr[i]);
            }
            Pr("\n");
        }

};

int main()
{
    Heap a;
    a.push(1);
    a.push(5);
    a.push(-4);
    a.push(7);
    a.Heapsort();
    a.show();
    a.buildhip();
    a.show();
    a.Heapsort();
    a.show();
}
