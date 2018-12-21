import sys
sys.setrecursionlimit(2000)
from collections import Counter
import math
from functools import reduce

if __name__ == "__main__":

    # single variables
    s = [str(val) for val in input().split()][0]

    s.replace(' ', '')
    n = float(len(s))
    n_2 = n ** (0.5)
    l = math.floor(n_2)
    h = math.ceil(n_2)
    
    for j in range(h):
        for i in range(l+1):
            ind = i*h+j
            if(ind < n):
                print(s[ind], end='')
        print(' ', end='')
    print('')     


