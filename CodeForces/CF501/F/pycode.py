import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()

def ways_from(ways, scale, length):
    # how many ways can i make a regular expression
    # that is equal to scale and has len length?

    if(scale < 0):
        return 0

    if(length == 0):
        return int(scale == 0)

    if((scale, length) in ways):
        return ways[(scale, length)]
    
    # try both ways on leftmost char
    ways1 = ways_from(ways, scale-1, length-1)
    ways2 = ways_from(ways, scale+1, length-1)

    ways[(scale, length)] = ways1 + ways2
    return ways[(scale, length)]


if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]
    s = input()

    cache = {}
    print(ways_from(cache, 0, 2))   


 

