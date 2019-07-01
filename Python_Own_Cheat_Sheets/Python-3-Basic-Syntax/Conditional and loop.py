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


# freopen("in.txt", "r", sys.stdin)
# freopen("out.txt","w",sys.stdout)

#we will take input n
#then we will take input n arrays each consisting several numbers(unspecified)
#then we will sort the numbers based on their frequency and then value
#then we will print the sorted numbers in pairs <number, frequency>
#maximum value of number in any set is 1000

def main():
    n=int(input())
    ctr = []
    ctr = [0]*(1001) #in c: int ctr[1001]={0};
    array_of_tuples=[] #declaring a list of tuples
    #python for loop can only iterate through once, no and , or etc are allowed
    #to check additional conditions use if just inside the for loop
    #while loop although acts same as C
    #although their for/while loops have else: option :D
    for i in range(1,n+1, +1):
        if(n < 0 or (1 * 1 != 1) or (2*2 != 4)): #additional statements that cannot be written in for loop
            break
        arr = []
        arr = list(map(int, input().split()))
        ln = len(arr)
        j = 0
        while(j < ln):
            ctr[arr[j]]+=1
            j+=1

    else:
        print("loop ends")




    for i in range(0, 1001, +1):
        if(ctr[i] > 0):
            tuple_temp = (i,ctr[i]) #this is how you create a tuple/n pair
            array_of_tuples.append(tuple_temp) #this is how list acts both like an array and vector
            #it also acts like a linked_list. if you want to insert at index ii (ii < length of list)
            #simply do this: array_of_tuples.insert(ii, tuple_temp)


    #Sorting the list of anything
    array_of_tuples.sort(key = lambda x:(x[1],x[0]), reverse=True)
    #cmp=if you had any custom compare function, you could have included it
    #or
    #key = On which elements of the tuples should the sort be done,
    #I gave x[1] as first key,
    #which means the whole list would first be sorted on the basis of index 1, or second element
    #Then I gave x[0] or element 1st, that means then the sorted on 2nd element array would be resorted
    #on the basis of 1st element. That means the order of the second elements won't be disoriented
    #only the first elements would be ordered inside each of the second element scopes
    #lile [(99,0), (1,3), (-1,3)] if it was like this, it would simply become [(99,0), (-1,3), (1,3)]

    #YOU CAN EITHER USE key=, OR cmp= function, not both together


    #reverse=True means, I want them to present the array as non-increasing order.
    #default way to sort is in increasing order

    ln=len(array_of_tuples)
    for i in range(ln):
        print(array_of_tuples[i])


    #****************MAP/ DICTIONARY IN PYTHON 3 ************************#
    # then we will do the some thing using a dictionary data structure (map in c++)
    # key of dictionary can be any single data type, or any tuple (n pair)

    map1 = dict({})  # declaring a dictionary, map is a reserved keyword, so is dict
    # for i in range(ln):
    #     map1[array_of_tuples[i][0]]=array_of_tuples[i][1]
    map1[(1,2)]=[2,4,6,-1,-99]
    map1[(1,1)]=[5]

    #To remove an entry
    #>>>del map1[key]
    #To delete all entries
    #>>>map1.clear()
    #To delete the dictionary
    #>>>del map1
    #to sort a dictionary

    for i in sorted(map1.keys()):
        map1[i]=sorted(map1[i])
        print(i, map1[i])

if (__name__ == '__main__'):
    main()