#include <iostream>
#include <unordered_map>
#define li long long int
using namespace std;

const li P = 1000000007;

/* Fast fibonacci with O(1) memory and O(lg n) time complexity. No cache. */

li fib_uncached (li n)
{
    /* find MSB position */
    li msb_position = 31;
    while (!((1 << (msb_position-1) & n)) && msb_position >= 0)
        msb_position--;

    li a=0, b=1;

    for (li i=msb_position; i>=0;i--)
    {
        li d = (a%P) * ((b%P)*2 - (a%P) + P),
            e = (a%P) * (a%P) + (b%P)*(b%P);
        a=d%P;
        b=e%P;

        if (((n >> i) & 1) != 0)
        {
            li c = (a + b) % P;
            a = b;
            b = c;
        }
    }
    return a;
}

/* Fast fibonacci using cache */
li fib (li n)
{
    static std::unordered_map<li,li> cache;

    if (cache.find(n) == cache.end())
    {
        li f;
        if (n==0)
            f = 0;
        else if (n < 3)
            f = 1;
        else if (n % 2 == 0)
        {
            li k = n/2;
            f = (fib(k) * (2*fib(k+1) - fib(k))) % P;
        }
        else
        {
            li k = (n-1)/2;
            f = (fib(k+1)*fib(k+1)+ fib(k) * fib(k)) % P;
        }
        if (f<0)
            f += P;

        cache[n] = f;
    }
    return cache.at(n);
}

int main ()
{
    li i ;
    cin >> i;
    cout << i << " : " << fib(i) << endl;
return 0;
}
