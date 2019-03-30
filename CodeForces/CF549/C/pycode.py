import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()
from copy import deepcopy


if __name__ == "__main__":

    # single variables
    n = [int(val) for val in sys.stdin.readline().split()][0]

    # On each step you select such a non-root vertex that it does not 
    # respect its parent and none of its children respects it

    tree = {i+1 : [[], []] for i in range(n)}
    for i in range(n):
        p, c = [int(val) for val in sys.stdin.readline().split()]
            
        tree[i+1][0].append((p, c))
        if(p != -1):
            tree[p][1].append((i, c))

    d = []
    for i in range(1, n+1):
        p, c = tree[i]
        if(p[0][1] == 1 and sum([x[1] for x in c]) == len(c)):
            d.append(i)

   
    if(len(d) == 0):
        print(-1)
    else: 
        for val in d:
            print(val, end=' ')
        print('')



