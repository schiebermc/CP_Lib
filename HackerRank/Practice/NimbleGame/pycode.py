import sys
sys.setrecursionlimit(2000)
from collections import Counter
# sys.stdin.readline()
import math
from functools import reduce

def nimbleGame(s, n):
    a=[]
    for i in range(n):
        a+=[i]*(s[i]%2)
    if a==[]:
        return 'Second'
    else:
        return 'First' if reduce((lambda x,y:x^y),a) else 'Second'

if __name__ == "__main__":

    # single variables
    t = [int(val) for val in input().split()][0]

    for test in range(t):

        n = [int(val) for val in input().split()][0]
        a = [int(val) for val in input().split()]        
        print(nimbleGame(a, n))

 
