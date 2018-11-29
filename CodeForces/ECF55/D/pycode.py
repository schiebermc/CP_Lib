import sys
sys.setrecursionlimit(2000)
from collections import Counter

def solution(n, a):

    if(n == 1): 
        print("NO")

    edges = {}
    for i in range(n):
        if(i == 0):
            edges[i] = [[1], []]
        elif(i == n-1):
            edges[i] = [[n-2], []]
        else:
            edges[i] = [[i-1], [i+1]]

    for ind, val in enumerate(a):
        lenl = len(edges[ind][0])
        lenr = len(edges[ind][0])
        remaining = val - lenl - lenr
        if(remaining < 0):
            print("NO")
            return
        
        polar = 0 if lenl > lenr else 1
    
        while(remaining != 0):
    
            val1 = edges[ind][0][-1]-1
            val2 = edges[ind][1][-1]+1

            if(val1 < 0):
                if(val2 >= n):
                    print("NO")
                    return
                else:
                    polar = 1

            if(val2 >= n):
                if(val1 < 0):
                    print("NO")
                    return
                else:
                    polar = 0
            
            if(polar == 0): # add left

                edges[ind][0].append(val1)             

            else:  # add right

                edges[ind][1].append(val2)             


            polar = 1 - polar
            remaining -= 1


    print(edges)


if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]

    # vectors
    a = [int(val) for val in input().split()]

    # solve it!
    solution(n, a)



