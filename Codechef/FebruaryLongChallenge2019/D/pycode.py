import sys
sys.setrecursionlimit(2000)
from collections import Counter
# sys.stdin.readline()

def solution(n, a):
    print(n, a)

if __name__ == "__main__":

    t = [int(val) for val in input().split()][0]
    for test in range(t):
        n = [int(val) for val in input().split()][0]
        a = [int(val) for val in input().split()]
        summ = 0
        for i in a:
            summ += (i-1)

        print(summ + 1)



