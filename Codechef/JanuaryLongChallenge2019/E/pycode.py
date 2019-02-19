import sys
sys.setrecursionlimit(2000)
from collections import Counter
# sys.stdin.readline()

def get_legal_neighbors(row, col, n, m):

    neighbors = []
    if(col+1 < m):
        neighbors += [[row, col+1]]

    if(row+1 < n):
        neighbors += [[row+1, col]]
        
    if(col-1 > 0):
        neighbors += [[row, col-1]]
    
    if(row-1 > 0):
        neighbors += [[row-1, col]]

    return neighbors


def get_neighbor_values(g, neighbors):
    return [g[row][col] for row, col in neighbors]


def validate_grid(grid, n, m):
    g = [[col[0] for col in row] for row in grid]
    good = True
    for row in range(n):
        for col in range(m):
            neighbors = get_legal_neighbors(row, col, n, m)
            values = get_neighbor_values(g, neighbors)
            good = good and len(set(values)) == len(neighbors)

    assert good
    assert max([max(row) for row in g]) < 5

    return good


def validate(bulk_grid):
    from random import seed
    from random import randint
       
    for n in range(1, 51): 
        for m in range(1, 51): 
            g = solution(n, m, bulk_grid)
            val = validate_grid(g, n ,m)
            assert val


def solution(n, m, bulk_grid=None):

    if(bulk_grid != None and n > 2 and m > 2):
        return [[bulk_grid[row][col] for col in range(m)] for row in range(n)]

    n2 = n+1 if n%2 == 1 and n != 1 else n
    m2 = m+1 if m%2 == 1 and m != 1 else m

    g = [[[None, set([1, 2, 3, 4, 5])] for col in range(m2)] for row in range(n2)]
    for row in range(n2):
        for col in range(m2):
            
            val = min(g[row][col][1])

            # special cases
            if(n2 == 1):
                val = (col//2)%2 + 1
            elif(m2 == 1):
                val = (row//2)%2 + 1
            elif(n2 == 2):
                val = col%3+1
            elif(m2 == 2):
                val = row%3+1
            
            g[row][col][0] = val
           
            # all neighbors of distance two cannot be this value
            dist2_neighbors = [[row+1, col-1], [row+2, col], [row+1, col+1], [row, col+2]]

            for row2, col2 in dist2_neighbors:
                if(col2 >= 0 and row2 < n2 and col2 < m2 and val in g[row2][col2][1]):
                    g[row2][col2][1].remove(val)
    if(n2 != n):
        g = g[:n]
    if(m2 != m):
        for i in range(n):
            g[i].pop()
    return g 

if __name__ == "__main__":

    bulk_grid = solution(50, 50)
    #validate(bulk_grid)

    t = [int(val) for val in input().split()][0]


    for test in range(t):
        n, m = [int(val) for val in input().split()]
        
        g = solution(n, m, bulk_grid)
        maxx = max([max(row) for row in g])
        
        print(maxx[0])
        for row in range(n):
            for col in range(m):
                print("%d " % g[row][col][0], end='')
            print('')





