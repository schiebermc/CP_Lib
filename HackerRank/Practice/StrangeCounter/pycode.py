import sys
sys.setrecursionlimit(2000)
from collections import Counter
# sys.stdin.readline()
import math

def get_number(g):
    divs = int(math.ceil(g/3))
    p = math.floor(math.log(divs, 2))
    start = int(((2**p)-1)*3)+1
    size = int(2**(p)*3)
    return size - (abs(start - g))

if __name__ == "__main__":

    # single variables
    g = [int(val) for val in input().split()][0]
    print(get_number(g))


