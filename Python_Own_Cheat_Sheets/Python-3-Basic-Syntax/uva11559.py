#Fahim Ahmed :: Dhaka Residential Model College
#Python is an unstacked language, so no stack command :D
#I am madly in love with python for its beauty
#But I will always love c++ for its speed <3

import sys
import math
import os
import filecmp
import fileinput
import cmath
import cmd
import operator
import collections

def freopen(f,option,stream):
    oldf = open(f,option)
    oldfd = oldf.fileno()
    newfd = stream.fileno()
    os.close(newfd)
    os.dup2(oldfd, newfd)

def main():
    while True:
        try:
            n,b,h,w=map(int, input().split())
            mini = 1000000008
            capacity =[[None for _ in range(w+1)] for _ in range(h+1)]
            p=[None]*(h+1)
            for i in range(0,h,+1):
                p[i] = int(input())
                capacity[i]=list(map(int, input().split()))
                for j in range(0, w, +1):
                    if(capacity[i][j] >= n):
                        mini=min(mini,n*p[i])


            if(mini > b):
                print("stay home")
            else:
                print(mini)
        except EOFError:
            break;


# freopen("in.txt", "r", sys.stdin)
# freopen("out.txt","w",sys.stdout)

if __name__ == '__main__':
    main()