import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()

def solution(n, a):
    print(n, a)

if __name__ == "__main__":

    # single variables
    t = [int(val) for val in input().split()][0]

    for test in range(t):
        
        n = [int(val) for val in input().split()][0]
        dishes = []
        for dish in range(n):
            dishes.append(set(input()))

        specials = reduce(lambda x,y : x.intersection(y), dishes)
        print(len(specials))



