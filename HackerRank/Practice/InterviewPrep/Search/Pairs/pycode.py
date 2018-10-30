# use this as the main template for python problems
from collections import Counter

def solution(n, k, a):

    c = Counter(a)
    count = 0
    for key in c:
        l = key - k
        if(l in c):
            count += c[key]*c[l]
    print(count)


if __name__ == "__main__":

    # single variables
    n, k = [int(val) for val in input().split()]

    # vectors
    arr = [int(val) for val in input().split()]

    # solve it!
    solution(n, k, arr)

