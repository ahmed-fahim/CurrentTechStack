import sys
import os
sys.setrecursionlimit(10000001);
import math
import filecmp
import fileinput
import cmath
import cmd
import operator
import collections


# freopen("in.txt", "r", sys.stdin)
# freopen("out.txt","w",sys.stdout)

def freopen(f,option,stream):
    oldf = open(f,option)
    oldfd = oldf.fileno()
    newfd = stream.fileno()
    os.close(newfd)
    os.dup2(oldfd, newfd)

#BITWISE operations
def check(i,k):
    return bool(i & (1<<k));
def On(i,k):
    return (i | (1<<k));
def Off(i,k):
    if(check(i,k) == True):
        v=1
    else:
        v=0
    return (i-(v << k));

#gcd,lcm
def gcd(a,b):
    while (b > 0):
        a=a%b;
        a,b=b,a;
    return a;

def lcm(a,b):
    return a* (b/gcd(a,b));

#Section SIV()
#notprime[i] = True means i is not a prime
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

def main():
    print("Hellow world\n", end='')
    #Your code goes here

if __name__=="__main__":
    main();