import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()

from itertools import combinations
import heapq

def solution1(n, k, songs):

    songs.sort(key=lambda x: x[1], reverse=True)

    heap = []
    best = 0
    length = 0

    for l, height in songs:
    
        length += l
        heapq.heappush(heap, l)

        if(len(heap) > k):
            
            val = heapq.heappop(heap)
            length -= val

        best = max(best, length * height)
    
    return best


def brute_force(n, k, songs):
    best = 0
    for size in range(1, k+1):
        for combo in combinations(songs, size):
            summ = sum([val[0] for val in combo])    
            minn = min([val[1] for val in combo])    
            best = max(best, minn*summ)
    return best

def validate():
    from random import seed
    from random import randint
    n = 10
    lmax = 100
    bmax = 100
    ntests = 25
    for test in range(ntests):
        seed(test)
        k = randint(1, n)
        songs = []
        for i in range(n):
            songs.append([randint(1, lmax), randint(1, bmax)])
        print("seed: %d" % (test))
        val1 = solution1(n,k,songs)
        val2 = brute_force(n,k,songs)
        try:
            assert val1 == val2
            print("passed")
        except:
            print("failed", songs, val1, val2)
    
        print('') 


if __name__ == "__main__":
    #validate()
    # single variables
    n, k = [int(val) for val in sys.stdin.readline().split()]
    songs = [[int(val) for val in sys.stdin.readline().split()] for song in range(n)]
    #print(brute_force(n, k, songs))
    print(solution1(n, k, songs))
    

