import sys
sys.setrecursionlimit(2000)
from collections import Counter

def solution(na, nb, nc, a, b, c):

    a = list(set(a))
    b = list(set(b))
    c = list(set(c))

    na = len(a)
    nb = len(b)
    nc = len(c)

    a.sort()
    b.sort()
    c.sort()

    count = 0
    inda = 0
    indb = 0
    indc = 0

    while(indb < nb):

        while(inda < na and a[inda] <= b[indb]):
            inda += 1 
        while(indc < nc and c[indc] <= b[indb]):
            indc += 1 

        count += (inda)*(indc)

        indb += 1
    print(count)

if __name__ == "__main__":

    # single variables
    na, nb, nc = [int(val) for val in input().split()]

    # vectors
    a = [int(val) for val in input().split()]
    b = [int(val) for val in input().split()]
    c = [int(val) for val in input().split()]

    solution(na, nb, nc, a, b, c)



