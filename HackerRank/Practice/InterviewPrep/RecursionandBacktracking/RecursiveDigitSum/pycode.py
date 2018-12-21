import sys
sys.setrecursionlimit(2000)
from collections import Counter

if __name__ == "__main__":

    # single variables
    n, k = [str(val) for val in input().split()]
    p = n
    p = str(int(k) * sum([int(val) for val in p]))
    while(len(p) > 1):
        p = str(sum([int(val) for val in p]))
    print(int(p))

