# use this as the main template for python problems
from collections import Counter

def solution(n, arr):

    tots = 0
    c = Counter(arr)
    for key, val in c.items():
        tots += val // 2
    print(tots)

if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]

    # vectors
    arr = [int(val) for val in input().split()]

    # solve it!
    solution(n, arr)



