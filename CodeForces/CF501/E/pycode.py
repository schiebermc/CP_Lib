import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()

def determine_star(grid, row, col, n, m):
    size = 1
    while(True):
        score = 0
        score += int(col+size <  m and grid[row][col+size])
        score += int(col-size >= 0 and grid[row][col-size])
        score += int(row+size <  n and grid[row+size][col])
        score += int(row-size >= 0 and grid[row-size][col])
        if(score == 0):
            if(size == 1):
                return (False, 0)
            else:
                return (True, size-1)
        elif(score < 4):
            if(size != 1):
                return (True, size-1)
            else:
                return (False, 0)
        size += 1     

def cover_star(grid, row, col, size):
    ind = 0
    while(ind <= size):
        grid[row+ind][col] = False
        grid[row-ind][col] = False 
        grid[row][col+ind] = False
        grid[row][col-ind] = False
        ind += 1

if __name__ == "__main__":

    # single variables
    n, m  = [int(val) for val in input().split()]
    grid = [[True if val == '*' else False for val in input()] for row in range(n)]

    stars = []
    for row in range(n):
        for col in range(m):
            if(grid[row][col]):
                thing = determine_star(grid, row, col, n, m)
                if(thing[0]):
                    stars.append((row, col, thing[1]))

    for star in stars:
        cover_star(grid, star[0], star[1], star[2])

    print(grid)
    summ = 0
    for row in range(n):
        summ += sum([1 for val in grid[row] if val == '*'])
    if(summ == 0):
        print(len(stars))
        for star in stars:
            print(star[0]+1, star[1]+1, star[2])    
    else:
        print(-1)



