import sys
sys.setrecursionlimit(2000)
from collections import Counter
import math
from functools import reduce

def getans(s):
    s2 = reduce(lambda x, y : x+y, sorted(s, reverse=True))
    if(s2 == s):
        return "no answer"

    for i in range(len(s)-1, -1, -1):
        for j in range(i-1, -1, -1):
            if(s[i] > s[j]):
                tmp =  s[:j] + s[i]
                s = s[:i] + s[i+1:]
                tmp += reduce(lambda x, y : x+y, sorted(s[j:]))
                return tmp

if __name__ == "__main__":

    # single variables
    q = [int(val) for val in input().split()][0]

    for test in range(q):

        s = [str(val) for val in input().split()][0]

        print(getans(s))

