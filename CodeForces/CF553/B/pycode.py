import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()

if __name__ == "__main__":

    # single variables
    n, m = [int(val) for val in sys.stdin.readline().split()]
    
    A = []
    for i in range(n):
        A.append([(ind, int(val)) for ind, val in enumerate(sys.stdin.readline().split())])

    M = []
    for row in range(n):
        M.append([])
        s = set([])
        for col in range(m):
            val = A[row][col][1]
            if(not val in s):
                s.add(val)
                M[row].append((A[row][col][0], val))

    pos = False    
    import itertools
    for T in itertools.product(*M):
        ans = T[0][1]
        for val in T[1:]: #N^4 :(
            ans = ans ^ val[1]
        if(ans != 0):
            print("TAK")
            for val in T:
                print(val[0]+1, end=' ')
                pos = True
            print("")
            break

    if(not pos):
        print("NIE")


