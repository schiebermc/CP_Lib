import sys
sys.setrecursionlimit(2000)
from collections import Counter
# sys.stdin.readline()

if __name__ == "__main__":

    # single variables
    n, m = [int(val) for val in input().split()]
    a = [int(val) for val in input().split()]
    
       
    a.sort()
    ldist = a[0] - 0
    rdist = n-1 - a[-1]

    dist = max(ldist, rdist)
    for ind in range(m-1):
        mid = a[ind] + (a[ind+1] - a[ind])//2
        val = min(abs(mid - a[ind+1]), abs(mid - a[ind]))
        dist = max(dist, val)
    print(dist)
