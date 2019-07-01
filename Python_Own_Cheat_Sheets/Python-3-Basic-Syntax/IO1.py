# For heavy recursion mathematical problem, python is really really bad
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


def freopen(f, option, stream):
    oldf = open(f, option)
    oldfd = oldf.fileno()
    newfd = stream.fileno()
    os.close(newfd)
    os.dup2(oldfd, newfd)


# freopen("in.txt", "r", sys.stdin)
# freopen("out.txt","w",sys.stdout)

# Reading two integers, m and n
m, n = map(int, input().split())

# printing their summation
print(m + n)

# printing them seperately
print(m, n)

# printing them along with another string
print("m =", m, " n =", n)
# the ',' operator itself prints another space
# if you don't want a space then simply do this
s = str("m=" + str(m) + "n=" + str(n))
print(s)

# python print() itself prints a newline, if you want to suppress this newline
print("Hi ", end='')  # end='' suppresses the newline
print("Hellow!! See ?? No newline made")

# ****************************************************************************************
# FORMAT SPECIFIER
# if you wanted to print the integer using format specifier
print("%d" % (m + n), end='')
print(" is the sum of %d %d" % (m, n))  # The different variables for all the specifiers %(v1,v2,.....,vn)

# now to read m number of inputs of type int
arr = list(map(int, input().split()))

for i in range(0, n, +1):
    print(arr[i], "where i=", i, type(arr[i]))
    # In python the intendation is a major thing

# Declaring a 1 dimensional array of length ln
ln = 10
a = [None] * ln

# Declaring a 2 dimensional array with row=3, col=5
row = 3
col = 5
matrix = [[None for _ in range(col)] for _ in range(row)]
matrix[0][0] = 111
print(matrix[0][0])

# If you have to read unknown number of integers from a line
arr = list(map(int, input().split()))
array_size = len(arr)

# If you want to read until EOF
while True:
    try:
        # For one variable input in a line don't use map(type, input())
        # use variable = type(input())
        n = int(input())
        print(n)
    except EOFError:
        break

# If you wanted to have a main function like c++
# Declare all your methods first
# then write
# def main():
#	#what main should do

# if __name__ == '__main__':
#	main()
