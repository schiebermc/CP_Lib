import sys
from collections import Counter
sys.setrecursionlimit(2000)

if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]
    a = [int(val) for val in input().split()]

    c = Counter(a)
    maxx = max([val for key, val in c.items()])
    print(n - maxx)
    


