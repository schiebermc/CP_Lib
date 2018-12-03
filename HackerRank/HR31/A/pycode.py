import sys
sys.setrecursionlimit(2000)
from collections import Counter
from math import ceil

if __name__ == "__main__":

    # single variables
    n, h = [int(val) for val in input().split()]

    w = [int(val) for val in input().split()]
    l = [int(val) for val in input().split()]


    best = 0.
    for i in range(n):
        val = w[i] - l[i]*0.25
        best = max(best, val)
   
    best = int(ceil(best))
    ladder = max(0, best - h) 
    print(ladder)


