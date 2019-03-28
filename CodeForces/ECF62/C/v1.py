import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()

from itertools import combinations

def solution1(n, k, songs):
    best = 0
    summ = 0
    minn = float('inf')
    songs.sort(key=lambda x : x[0], reverse=True)
    songs.sort(key=lambda x : x[1], reverse=True)
    for i in range(k):
        summ += songs[i][0]
        minn = min(minn, songs[i][1])
        best = max(best, minn*summ)
    summ = 0
    minn = float('inf')
    songs.sort(key=lambda x : x[0]*x[1], reverse=True)
    songs.sort(key=lambda x : x[1], reverse=True)
    songs.sort(key=lambda x : x[0], reverse=True)
    for i in range(k):
        summ += songs[i][0]
        minn = min(minn, songs[i][1])
        best = max(best, minn*summ)
    summ = 0
    minn = float('inf')
    songs.sort(key=lambda x : x[0]*x[1], reverse=True)
    for i in range(k):
        summ += songs[i][0]
        minn = min(minn, songs[i][1])
        best = max(best, minn*summ)
    summ = 0
    minn = float('inf')
    songs.sort(key=lambda x : x[0]*x[1]*x[1], reverse=True)
    for i in range(k):
        summ += songs[i][0]
        minn = min(minn, songs[i][1])
        best = max(best, minn*summ)
    summ = 0
    minn = float('inf')
    songs.sort(key=lambda x : x[0]*x[0]*x[1], reverse=True)
    for i in range(k):
        summ += songs[i][0]
        minn = min(minn, songs[i][1])
        best = max(best, minn*summ)
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
    validate()
    # single variables
    n, k = [int(val) for val in sys.stdin.readline().split()]
    songs = [[int(val) for val in sys.stdin.readline().split()] for song in range(n)]

    

