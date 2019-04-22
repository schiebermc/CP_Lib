import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()

if __name__ == "__main__":

    # single variables
    n, m = [int(val) for val in sys.stdin.readline().split()]
    
    M = []
    for i in range(n):
        M.append([int(val) for val in sys.stdin.readline().split()])
    
    a = []
    for i in range(n):
        a.append(Counter(M[i]))

    inds = []
    for row in range(n):
        inds.append({})
        for col in range(m):
            inds[row][M[row][col]] = col+1

    s = reduce(lambda x, y: x+y, a)
    
    if(len(s) == 1):
        val = list(s.keys())[0]
        if(n%2 == 0 or val == 0):
            print("NIE")
        else:
            print("TAK")
            for x in range(n):
                print(val, end=' ')
            print('')
    else:
        A =[[key for key, val in row.items()] for row in a]
        import itertools
        for t in itertools.product(*A):
            ans = reduce(lambda x, y : x^y, t)
            if(ans != 0):
                for ind, val in enumerate(t):
                    print(inds[ind][val], end=' ')
                print('')
                break
     


