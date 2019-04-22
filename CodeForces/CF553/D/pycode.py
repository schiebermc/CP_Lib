import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()

if __name__ == "__main__":

    # single variables
    n = [int(val) for val in sys.stdin.readline().split()][0]
    v = []
    for i in range(n):
        v.append([int(val) for val in sys.stdin.readline().split()])

    a = [(ind, val[0]) for ind, val in enumerate(v)]
    b = [(ind, val[1]) for ind, val in enumerate(v)]

    a.sort(key=lambda x: x[1])
    b.sort(key=lambda x: x[1])
    
    s = set([])

    front = 1
    back  = n
    d = 0
    order = [0]*n
    while(len(s) != n):
        aind, aval = a[-1]
        bind, bval = b[-1]
        if(aval > bval):
            a.pop()
            if(aind in s):
                continue
            else:
                bval = v[aind][1]
                d += aval*(front-1) + bval*(n-front)
                order[front-1] = aind
                front += 1
                s.add(aind)
        else:
            b.pop()
            if(bind in s):
                continue
            else:
                aval = v[bind][0]
                d += aval*(back-1) + bval*(n-back)
                order[back-1] = bind
                back -= 1
                s.add(bind)

    print(d)





