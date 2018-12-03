import sys
sys.setrecursionlimit(2000)
from collections import Counter
from math import log

if __name__ == "__main__":

    # single variables
    x, y = [int(val) for val in input().split()]

    if(x > 3 and y > 3):

        if(x < y):
            ans = '>'
        elif(x > y):
            ans = '<'
        else:
            ans = '='

    else:
        
        val1 = log(x) / x
        val2 = log(y) / y

        if(val1 > val2):
            ans = '>'
        elif(val1 < val2):
            ans = '<'
        else:
            ans = '='


    print(ans)
