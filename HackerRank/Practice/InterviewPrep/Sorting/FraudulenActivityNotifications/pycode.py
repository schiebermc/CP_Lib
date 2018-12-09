import sys
sys.setrecursionlimit(2000)
from collections import Counter

def solution(n, d, a):

    a.sort()

    days = [0] * d
    count = 0
    for ind, val in enumerate(a):
        
        if(ind < d):
            days[ind] = val
            continue
         
        print(days)

        if(d % 2 == 1):
            median = days[d//2]
        else:
            median = float(days[d//2]+days[d//2+1])/2.

        print(median)
        if(val > median):
            count += 1
        
        # udpate trailing days
        days[0] = val
        days.sort()
        
    print(count)
            


if __name__ == "__main__":

    # single variables
    n, m  = [int(val) for val in input().split()]

    # vectors
    a = [int(val) for val in input().split()]

    # solve it!
    solution(n, m, a)



