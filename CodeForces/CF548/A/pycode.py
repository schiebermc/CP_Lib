import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()

if __name__ == "__main__":

    # single variables
    n = [int(val) for val in sys.stdin.readline().split()][0]
    s = input()

    count = 0
    for ind, val in enumerate(s):
        if(int(val)%2 == 0):
            count += ind+1

    print(count)

    



