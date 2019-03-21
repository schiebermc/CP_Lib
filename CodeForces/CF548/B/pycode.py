import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()

if __name__ == "__main__":

    # single variables
    n = [int(val) for val in sys.stdin.readline().split()][0]
    a = [int(val) for val in sys.stdin.readline().split()]


    prev = a[-1]
    count = prev
    for i in range(n-2, -1, -1):
        prev = min(a[i], prev-1)
        prev = max(prev, 0)
        count += prev

    print(count)       
 

