import sys
sys.setrecursionlimit(2000)
from collections import Counter
# sys.stdin.readline()

if __name__ == "__main__":

    # single variables
    n, m = [int(val) for val in input().split()]
    
    # vectors
    a = [int(val) for val in input().split()]
    b = [int(val) for val in input().split()]

    a = [(val, ind) for ind, val in enumerate(a)]
    b = [(val, ind) for ind, val in enumerate(b)]
    
    a.sort()
    b.sort()

    for i in range(n):
        print(a[i][1], b[0][1])
    for j in range(1, m):
        print(a[n-1][1], b[j][1])


