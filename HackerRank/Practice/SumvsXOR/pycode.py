import sys
sys.setrecursionlimit(2000)
from collections import Counter
# sys.stdin.readline()
import math

if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]
    c = sum([int(val) for val in bin(n)[2:]])
    print(2**c)
 
