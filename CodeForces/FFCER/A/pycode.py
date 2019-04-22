import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()

if __name__ == "__main__":

    s = input()
    n = len(s)
    c = Counter(s)
    a = c['a']
    
    v = a*2-1
    if(n <= v):
        print(n)
    else:
        print(v)    


