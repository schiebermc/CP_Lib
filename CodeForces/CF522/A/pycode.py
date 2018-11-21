# use this as the main template for python problems
from collections import Counter
from math import ceil

def solution(k, n, a):

    c = Counter(a)
    min_dishes = 0
    for key, val in c.items():
        min_dishes = max(min_dishes, ceil(val / n))

    total_dishes  = 0
    wrap = min_dishes * n
    for key, val in c.items():
        amount = wrap - (val % wrap)
        if(amount != wrap):
            total_dishes += amount
    print(total_dishes)

if __name__ == "__main__":

    # single variables
    n, k = [int(val) for val in input().split()]

    # vectors
    arr = [int(val) for val in input().split()]

    # solve it!
    solution(n, k, arr)

