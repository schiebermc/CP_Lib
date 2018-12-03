import sys
sys.setrecursionlimit(2000)
from collections import Counter


def is_prime(n):
    sqrtn = int(n**(0.5))
    for i in range(2, sqrtn+1):
        if(n%i == 0):
            return False
    return True

if __name__ == "__main__":

    # single variables
    q = [int(val) for val in input().split()][0]

    for i in range(q):

        n = [int(val) for val in input().split()][0]


        t = False if n == 1 else is_prime(n)

        if(t):
            print("Prime")
        else:
            print("Not prime")


