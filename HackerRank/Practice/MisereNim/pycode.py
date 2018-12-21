import sys
sys.setrecursionlimit(2000)
from collections import Counter
# sys.stdin.readline()
import math
from functools import reduce

def misereNim(s, n):
    if (set(s)=={1}) and n%2==1:
        return 'Second'
    elif (set(s)=={1}) and n%2==0:
        return 'First'
    elif reduce((lambda x,y:x^y),s):
        return 'First'
    else:
        return 'Second'

if __name__ == "__main__":

    # single variables
    t = [int(val) for val in input().split()][0]

    for test in range(t):

        n = [int(val) for val in input().split()][0]
        a = [int(val) for val in input().split()]        
        print(misereNim(a, n))

 
