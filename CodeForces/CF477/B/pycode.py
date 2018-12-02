import sys
sys.setrecursionlimit(2000)
from collections import Counter

def solution(n, A, B, s):

    summ = sum(s)
    val = s[0]
    s = sorted(s[1:], reverse=True)

    count = 0
    frac = val / summ
    while(A*frac < B):
        summ -= s[count]
        count += 1
        frac = val / summ

    print(count)

if __name__ == "__main__":

    # single variables
    n, A, B = [int(val) for val in input().split()]

    # vectors
    s = [int(val) for val in input().split()]

    # solve it!
    solution(n, A, B, s)



