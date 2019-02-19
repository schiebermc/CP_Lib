import sys
sys.setrecursionlimit(2000)
from collections import Counter
# sys.stdin.readline()

def solution(n, a):
    print(n, a)

if __name__ == "__main__":

    # single variables
    t = [int(val) for val in input().split()][0]

    for test in range(t):

        n = [int(val) for val in input().split()][0]
        a = [int(val) for val in input().split()]
        d = [int(val) for val in input().split()]

        survivors = []
        for ind in range(n):
            lind = (ind - 1) % n
            rind = (ind + 1) % n

            if(a[lind] + a[rind] < d[ind]):
                survivors.append(ind)

        best = -1
        for ind in survivors:
            best = max(d[ind], best)
        print(best)



