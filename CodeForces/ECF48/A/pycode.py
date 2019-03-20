import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()

if __name__ == "__main__":

    n, m = [int(val) for val in sys.stdin.readline().split()]
    a = [int(val) for val in sys.stdin.readline().split()]

    summ = 0
    divs = 0
    for val in a:
        divs1 = divs
        summ += val
        divs = summ // m
        print(divs - divs1, end=' ')
    print('')




