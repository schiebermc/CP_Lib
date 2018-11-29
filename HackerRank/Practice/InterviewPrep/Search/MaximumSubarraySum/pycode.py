import sys
sys.setrecursionlimit(2000)
from collections import Counter

def solution(n, m, a):

    solution(n, m, a)


def solution(n, m, a):

    summ = 0
    prefix_sums = [0] * n
    for ind, val in enumerate(a):
        summ = ((summ % m) + (val % m)) % m
        prefix_sums[ind] = summ

    

def brute_force(n, m, a):
    
    a = [val % m for val in a]

    best = 0
    for size in range(1, n+1):
        
        for start in range(0, n-size+1):

            val = mod_sum(a[start:start+size], m)
            best = max(val, best)
            
    print(best)


def mod_sum(vec, m):
    summ = 0
    for val in vec:
        summ = ((summ % m) + (val % m) ) % m
    return summ


if __name__ == "__main__":

    # single variables
    q = [int(val) for val in input().split()][0]
    n, m = [int(val) for val in input().split()]



    for i in range(q):

        # solve it!
        a = [int(val) for val in input().split()]
        solution(n, m, a)



