import sys
sys.setrecursionlimit(2000)
import heapq

if __name__ == "__main__":

    # single variables
    n, k = [int(val) for val in input().split()]

    # vectors
    h = [int(val) for val in input().split()]
    heapq.heapify(h)

    count = 0
    while(len(h) != 1):
        val1 = heapq.heappop(h)
        val2 = heapq.heappop(h)
        if(val1 >= k):
            heapq.heappush(h,val1)
            heapq.heappush(h, val2)
            break
        heapq.heappush(h, 2*val2 + val1)
        count += 1
  
    val1 = heapq.heappop(h)
    if(val1 < k):
        print(-1)
    else:
        print(count)


