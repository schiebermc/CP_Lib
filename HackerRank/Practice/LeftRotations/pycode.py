import sys
sys.setrecursionlimit(2000)
from collections import Counter
# sys.stdin.readline()

if __name__ == "__main__":

    # single variables
    n, m = [int(val) for val in input().split()]

    # vectors
    a = [int(val) for val in input().split()]

    m = m % n
    count = 0
    while(count < n):
        print("%d " % (a[m%n]), end='')
        m += 1
        count += 1

    print('') 
    



