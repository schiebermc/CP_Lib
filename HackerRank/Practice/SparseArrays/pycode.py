import sys
sys.setrecursionlimit(2000)
from collections import Counter
import math
from functools import reduce

if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]
    d = {}
    for i in range(n):
        s = [str(val) for val in input().split()][0]

        if(s in d):
            d[s] += 1
        else:
            d[s] = 1

    q = [int(val) for val in input().split()][0]
    for test in range(q):
        s = [str(val) for val in input().split()][0]
        if(s in d):
            print(d[s])
        else:
            print(0)
    
