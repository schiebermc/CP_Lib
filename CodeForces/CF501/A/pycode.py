import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()

if __name__ == "__main__":

    # single variables
    n, m = [int(val) for val in sys.stdin.readline().split()]

    points = set(range(1, m+1))
    for i in range(n):
        
        l, r = [int(val) for val in sys.stdin.readline().split()]
        for point in range(l, r+1):
            if point in points:
                points.remove(point)

        
    print(len(points))
    for point in points:
        print(point, end=' ')
    print('')
        


