import sys
sys.setrecursionlimit(2000)
from collections import Counter

def solution(n, a):
    print(n, a)

if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]

    a = {'purple' : 'Power',
         'green' : 'Time',
         'blue' : 'Space',
         'orange' : 'Soul',
         'red' : 'Reality',
         'yellow' : 'Mind'}

    for i in range(n):
        val = [val for val in input().split()][0]
        del a[val]

    print(len(a))
    for i in a:
        print(a[i])


