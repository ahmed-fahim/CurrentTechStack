#Successful with 1920ms timing. Python is slower than java/C++
import sys
sys.setrecursionlimit(10000001);
import math

#gcd,lcm
def gcd(a,b):
    while (b > 0):
        a=a%b;
        a,b=b,a;
    return a;

def lcm(a,b):
    return a* (b//gcd(a,b));

notprime = [False]*(10000001);
primes=[];

def store_primes(n):
    primes.append(2);
    primes.append(3);
    limit=n+1;
    i=6;
    while(i <= limit):
        a=i-1;
        if(notprime[a]==False):
            primes.append(a);
        a=i+1;
        if(notprime[a]==False):
            primes.append(a);
        i+=6;

def siv(n):
    sq = int(math.sqrt(n));
    notprime[0] = True;
    notprime[1] = True;

    for i in range(6,sq+1, +6):
        a=i-1;
        if (notprime[a]==False):
            j = a * a;
            inc = 2 * a;
            while(j<=n):
                notprime[j]=True;
                j+=inc;
        a=i+1;
        if (notprime[a] == False):
            j = a * a;
            inc = 2 * a;
            while (j <= n):
                notprime[j] = True;
                j += inc;
    store_primes(n);
def is_prime(val):
    if(val == 2):
        return True;
    elif(val % 2 == 0):
        return False;
    else:
        return not notprime[val];

squares=[];
def prime_square_generator(n):
    sq = int(math.sqrt(n));
    siv(sq);
    ln = len(primes);
    for i in range(0, ln, +1):
        squares.append(primes[i]*primes[i]);
    global m;
    m=len(squares);

def sq_free(current_index, product_b4, counter):
    global n,m;
    global res;

    if(product_b4 > n):
        return;

    if(counter % 2 == 0):
        res+=(n//product_b4);
    else:
        res-=(n//product_b4);

    for it in range(current_index, m,+1):
        if(squares[it] > n):
            break;
        v = product_b4*squares[it];
        if(v > n):
            break;
        sq_free(it+1, v, counter+1);

def main():
    prime_square_generator(100000000000000);
    print(is_prime(91))

if __name__=="__main__":
    main();