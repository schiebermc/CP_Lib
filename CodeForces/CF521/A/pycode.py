# use this as the main template for python problems
from collections import Counter

def solution(a, b, k):

    if(k%2==0):
        print((a - b)* (k//2))
    else:
        print((a - b)* (k//2) + a)
        


if __name__ == "__main__":

    # single variables
    t = [int(val) for val in input().split()][0]

    for i in range(t):
        # vectors
        a, b, k = [int(val) for val in input().split()]

        # solve it!
        solution(a, b, k)

