# use this as the main template for python problems
from collections import Counter

def solution(n, a, b):

    d1 = {}
    d2 = {}
    for i in range(4):
        for j in range(4):
            d1[(i, j)] = i or j
            d2[(i, j)] = i and j
        

    for key, val in d1.items():
        if(val == d2[key]):
            print(key)


if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]

    # vectors
    a = [int(val) for val in input().split()]
    b = [int(val) for val in input().split()]

    # solve it!
    solution(n, a, b)

