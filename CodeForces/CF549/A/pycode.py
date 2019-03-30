import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()

if __name__ == "__main__":

    # single variables
    n = [int(val) for val in sys.stdin.readline().split()][0]
    a = [int(val) for val in sys.stdin.readline().split()]

    val = a[-1]
    for i in range(n-1, -1, -1):
        if(a[i] == val):
            a.pop(i)
        else:
            break
        

    if(len(a) == 0):
        print(n)
    else:
        print(len(a))

        


