import sys
sys.setrecursionlimit(2000)
from collections import Counter
from math import ceil

def solution(n, x, y, d):

    diff = abs(x - y)
    if(diff % d == 0):
        print(distance(x, y, d))
    else:
        diff1 = abs(1 - y)
        diff2 = abs(n - y)
    
        if(diff1 % d != 0 and diff2 % d != 0):
            print(-1)
    
        elif(diff1 % d == 0 and diff2 % d != 0): # use first page
            print(distance(x, 1, d) + distance(1, y, d)) 
        elif(diff1 % d != 0 and diff2 % d == 0):
            print(distance(x, n, d) + distance(n, y, d)) 
        else:
            dist1 = distance(x, 1, d) + distance(1, y, d) 
            dist2 = distance(x, n, d) + distance(n, y, d)
            print(min(dist1, dist2)) 

    
def distance(x, y, d):
    return int(ceil(abs(x - y)/float(d)))

if __name__ == "__main__":

    # single variables
    q = [int(val) for val in input().split()][0]

    for x in range(q):

        # vectors
        n, x, y, d = [int(val) for val in input().split()]
    
        # solve it!
        solution(n, x, y, d)



