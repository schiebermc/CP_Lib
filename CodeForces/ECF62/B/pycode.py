import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()

if __name__ == "__main__":

    # single variables
    t = [int(val) for val in sys.stdin.readline().split()][0]

    for test in range(t):

        n = [int(val) for val in sys.stdin.readline().split()][0]
        s = input()

        c1 = n
        for i in range(n):
            if(s[i] == '>'):
                c1 = min(i, c1)
        
        c2 = -1
        for i in range(n-1, -1, -1):
            if(s[i] == '<'):
                c2 = max(i, c2)

        c2 = n - 1 - c2
        ans = min(c1, c2)

        print(ans)


