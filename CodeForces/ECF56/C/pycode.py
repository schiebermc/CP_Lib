import sys
sys.setrecursionlimit(2000)
from collections import Counter

if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]
    b = [int(val) for val in input().split()]

    l = 0
    r = b[0]
    a = [0] * n
    for i in range(n//2):
        a[i] = l
        a[n-1-i] = r
        if(i != n//2-1):
            val = b[i+1]
            summ = l + r
            if(summ == val):
                continue
            elif(summ > val):
                diff = summ - val
                r -= diff
            elif(summ < val):
                diff = val - summ
                l += diff

    for i in a:
        print(i, end=' ')
    print('')
       


