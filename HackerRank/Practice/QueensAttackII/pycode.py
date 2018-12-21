import sys
sys.setrecursionlimit(2000)
from collections import Counter
import math
from functools import reduce


def total_attacks_in_this_direction(r, c, row_shift, col_shift, n, obstacles):
    count = 0
    while(not (r < 0 or r >= n or c < 0 or c >= n or (r, c) in obstacles)):
        r += row_shift
        c += col_shift
        count += 1
    return count - 1

if __name__ == "__main__":

    # single variables
    n, k = [int(val) for val in input().split()]
    r, c = [int(val)-1 for val in input().split()]

    obstacles = set([])
    for ob in range(k):
        ro, co = [int(val)-1 for val in input().split()]
        obstacles.add((ro, co))

    tots = 0
    shifts = [-1, 0, 1]
    for row_shift in shifts:
        for col_shift in shifts:
            if(row_shift == 0 and col_shift == 0):
                continue
            tots += total_attacks_in_this_direction(r, c, row_shift, col_shift, n, obstacles)
    
    print(tots) 
    

