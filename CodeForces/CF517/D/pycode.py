# use this as the main template for python problems
from collections import Counter

def solution(n, a):

    



if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]

    # vectors
    a = [[ord(val) - 96 for val in input()] for i in range(n)]

    # solve it!
    solution(n, a)

