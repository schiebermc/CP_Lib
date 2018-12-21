import sys
sys.setrecursionlimit(2000)
from collections import Counter
# sys.stdin.readline()
from math import ceil

if __name__ == "__main__":

    # single variables
    n, k = [int(val) for val in input().split()]

    # vectors
    a = [int(val) for val in input().split()]
    page = 1
    count = 0
    for chapter, nproblems in enumerate(a):
        for problem in range(1, nproblems+1):
            if(problem == page):
                count += 1
            if(problem % k == 0):
                page += 1
        if(nproblems % k != 0):
            page += 1
    print(count)    



