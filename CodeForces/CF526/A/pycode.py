import sys
from math import ceil
if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]

    # vectors
    a = [int(val) for val in input().split()]

    best = float('inf')
    for x in range(1, 100):
        summ = 0
        for ind, val in enumerate(a):
            summ += (abs(x - (ind+1)) + abs((ind+1) - 1) + abs(x - 1))*val

        best = min(best, summ)

    print(best*2)


