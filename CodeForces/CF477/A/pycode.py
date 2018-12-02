import sys
sys.setrecursionlimit(2000)
from collections import Counter

def solution(n, s, planes):

    if(planes[0] > s):
        print("0 0")
        return

    find = 0
    for ind, val in enumerate(planes):
       
        find = ind
        if(ind != n-1 and abs(val - planes[ind+1]) >= 2*s  + 2):
            break

    time = planes[find] + s + 1
    h = time // 60
    m = time % 60
    print("%d %d" % (h, m))

if __name__ == "__main__":

    # single variables
    n, s = [int(val) for val in input().split()]

    # vectors
    planes = []
    for i in range(n):
    
        h, m = [int(val) for val in input().split()]
    
        planes.append(60*h + m)

    # solve it!
    solution(n, s, planes)



