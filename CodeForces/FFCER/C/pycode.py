import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()
from random import shuffle

if __name__ == "__main__":

    # single variables
    t = [int(val) for val in sys.stdin.readline().split()][0]
    
    for test in range(t):
        n = [int(val) for val in input().split()][0]
        results = []
        inds = [ind+1 for ind in range(n)]
        for i in range(9):
            shuffle(inds)
            s1 = inds[:n//2]
            s2 = inds[n//2:] 
            print("%d %d" % (len(s1), len(s2)), end=' ')
            for i in s1:
                print(i, end=' ')
            for i in s2:
                print(i, end=' ')
            sys.stdout.flush()
        
            val = [int(val) for val in input().split()][0]
            results.append(val)
        
        print("%d %d" % (-1, max(results)))
        sys.stdout.flush()
        if(val == -1):
            fuck




