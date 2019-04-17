import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()

if __name__ == "__main__":

    # single variables
    n = [int(val) for val in sys.stdin.readline().split()][0]
    a = list(set([int(val) for val in sys.stdin.readline().split()]))

    best = float("inf") 
    for med in range(101): 
        val = float("inf")
        diffs = set([abs(val - med) for val in a])
        if(len(diffs) == 1):
            val = list(diffs)[0]        
        elif((len(diffs) == 2 and 0 in diffs)):
            diffs.remove(0)
            val = list(diffs)[0]        
        best = min(val, best)
    
    if(best == float("inf")):
        print(-1)
    else:
        print(best)
