import sys
sys.setrecursionlimit(2000)
from collections import Counter
# sys.stdin.readline()
from itertools import combinations_with_replacement

if __name__ == "__main__":

    # single variables
    t = [int(val) for val in input().split()][0]

    
    for test in range(t):
        
        n = [int(val) for val in input().split()][0]
        a = [int(val) for val in input().split()][0]
        b = [int(val) for val in input().split()][0]

        pos = set([])
        for p in combinations_with_replacement([a, b], n-1):
            pos.add(sum(p))

        pos = list(pos)
        pos.sort()
        for p in pos:
            print(p, end=' ')
        print('')




