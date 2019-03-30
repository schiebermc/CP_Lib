import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()

if __name__ == "__main__":

    # single variables
    n, k = [int(val) for val in sys.stdin.readline().split()]
    a, b = [int(val) for val in sys.stdin.readline().split()]

    # x: min stops before returning to s
    # y: max stops before returning to s

    starts = [a, (k-a)%(k)]
    ends   = [b, (k-b)%(k)]

    x = float('inf')
    y = 0

    # unwrap the equivalence classes
    starts = [s+(k*i) for s in starts for i in range(n)]
    ends   = [s+(k*i) for s in ends   for i in range(n)]

    for start in starts:
        for end in ends:
            if(start == end):
                l = n*k
            else:
                if(start < end):
                    l = end - start
                else:
                    l = n*k + end - start    
 
            trips = 1
            s = end
            while(s != start):
                trips += 1
                s = (s + l) % (n*k)
            x = min(x, trips)
            y = max(y, trips)

    print(x, y) 
