import sys
sys.setrecursionlimit(2000)
from collections import Counter
import math
from functools import reduce


if __name__ == "__main__":

    # single variables
    n, k = [int(val) for val in input().split()]
    a = [int(val) for val in input().split()]

    c = Counter([val%k for val in a])
    includes = set([])
    for key, val in c.items():
        diff = k - key
        if(diff in c and val < c[diff]):
            continue    
        else:
            includes.add(key)

    tots = reduce(lambda x, y: x + y, [c[key] for key in includes])

    # two caveat
    if(0 in c):
        tots -= c[0]
        tots += 1

    if(k % 2 == 0):
        if(k//2 in c):
            tots -= c[k//2]
            tots += 1
    
    print(tots)
 
 
