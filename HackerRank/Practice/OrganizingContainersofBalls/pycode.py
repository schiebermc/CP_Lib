import sys
sys.setrecursionlimit(2000)
from collections import Counter
import math
from functools import reduce


if __name__ == "__main__":

    # single variables
    q = [int(val) for val in input().split()][0]

    # how can it not be possible?
    # the number of balls in a container never changes.

    for test in range(q):

        n = [int(val) for val in input().split()][0]
        M = [[int(val) for val in input().split()] for row in range(n)]

        container_sizes = [sum(balls) for balls in M]
        type_sizes = [sum([balls[col] for balls in M]) for col in range(n)]
        cc = Counter(container_sizes)
        ct = Counter(type_sizes)
        
        if(cc == ct):
            print("Possible")
        else:
            print("Impossible") 


