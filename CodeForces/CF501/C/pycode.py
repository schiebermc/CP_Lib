import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()

if __name__ == "__main__":

    # single variables
    n, m = [int(val) for val in sys.stdin.readline().split()]
    
    songs = []
    for song in range(n):

        a, b = [int(val) for val in sys.stdin.readline().split()]
        songs.append((a, b, a - b))

    songs.sort(key=lambda x: x[2], reverse=True)
    summ = sum([val[0] for val in songs])
    
    ind = 0
    while(ind < n and summ > m):
        summ -= songs[ind][2]
        ind += 1

    if(summ > m):
        print(-1)
    
    else:
        print(ind)


