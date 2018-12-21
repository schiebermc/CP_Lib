import sys
sys.setrecursionlimit(2000)
from collections import Counter
# sys.stdin.readline()
from math import ceil
if __name__ == "__main__":

    # single variables
    t = [int(val) for val in input().split()][0]


    for test in range(t):

        x = [int(val) for val in input().split()][0]
        print(int(ceil(float(x)/7.)))
        


