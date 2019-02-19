import sys
sys.setrecursionlimit(2000)
from collections import Counter
# sys.stdin.readline()

def solution(n, a):
    print(n, a)

if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]

    # vectors
    a = [int(val) for val in input().split()]

    # solve it!
    solution(n, a)



