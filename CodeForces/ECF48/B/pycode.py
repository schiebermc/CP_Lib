import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()

if __name__ == "__main__":

    # single variables
    n, m, q = [int(val) for val in sys.stdin.readline().split()]
    s = input()
    t = input()
    count = [int(s[i:i+m]==t) for i in range(n)]
    for query in range(q):
        l, r = [int(val)-1 for val in sys.stdin.readline().split()]
        print(sum(count[l:max(l, r+2-m)]))

    


