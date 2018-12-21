import sys
from collections import deque

if __name__ == "__main__":

    n = [int(val) for val in input().split()][0]
    grid =[]
    for i in range(n):  
        grid.append([str(val) for val in input()])

    x1, y1, fx2, fy2 = [int(val) for val in input().split()]
    paths = deque([(x1, y1, 0)])
    grid[x1][y1] = 'X'
    
    while(True):
        
        x1, y1, nmoves = paths.popleft()

        if(x1 == fx2 and y1 == fy2):
            break

        x2, y2 = x1, y1
        while(y2+1 < n and grid[x2][y2+1] != 'X'):
            y2 += 1
            paths.append((x2, y2, nmoves + 1))
            grid[x1][y1] = 'X'        

        x2, y2 = x1, y1
        while(x2+1 < n and grid[x2+1][y2] != 'X'):
            x2 += 1
            paths.append((x2, y2, nmoves + 1))
            grid[x1][y1] = 'X'        
    
        x2, y2 = x1, y1
        while(x2-1 >= 0 and grid[x2-1][y2] != 'X'):
            x2 -= 1
            paths.append((x2, y2, nmoves + 1))
            grid[x1][y1] = 'X'        
        
        x2, y2 = x1, y1
        while(y2-1 >= 0 and grid[x2][y2-1] != 'X'):
            y2 -= 1
            paths.append((x2, y2, nmoves + 1))
            grid[x1][y1] = 'X'        
    
    print(nmoves) 


