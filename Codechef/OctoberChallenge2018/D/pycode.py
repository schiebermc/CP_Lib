# use this as the main template for python problems
import sys
from heapq import heapify, heappush, heappop

def solution(n, m, a, b):

    # strategy
    # 1. use a min heap, each element is a day. save
    # the index of the day as the second element to access b[ind]
    # 2. continuously decrement the most expensive day using the balloons
    # that we have. push the new day back on the heap when accounted for.

    a = [[-1*a[ind]*b[ind], ind] for ind in range(len(a))]
    heapify(a)
    
    while(m != 0):
        day = heappop(a)
        if(day[0] > 0): ## we had more than enough baloons, gtfo
            break
        new_day = [day[0] + b[day[1]], day[1]]
        heappush(a, new_day)        
        m -= 1 

    print(max(0, -1*heappop(a)[0]))           
 

if __name__ == "__main__":

    # single variables
    n, m = [int(val) for val in sys.stdin.readline().split()]

    # vectors
    a = [int(val) for val in sys.stdin.readline().split()]
    b = [int(val) for val in sys.stdin.readline().split()]

    # solve it!
    solution(n, m, a, b)



