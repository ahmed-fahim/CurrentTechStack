#include <bits/stdc++.h>

using namespace std;

long long int fibonacci[100000000];
inline long long int fibonacci_gen(long long int n)
{
    if(n == 1) return 0;
    else if(n == 2) return 1;
    else if(fibonacci[n] != -1) return fibonacci[n];
    else
    {
        return fibonacci_gen(n-1) + fibonacci_gen(n-2);
    }
}

int main()
{
    clock_t start,stop;
    double time = 0.00;
    assert((start = clock()) != -1);

    long long int n = 50;
    for(long long int i = 0; i <= n; i++){ fibonacci[i] = -1;}

    long long int r = fibonacci_gen(n);

    printf("%lld = f(n)\n", r);



    stop = clock();
    time = (double) (stop-start)/CLOCKS_PER_SEC;
    printf("Run time: %lf\n", time);

}


