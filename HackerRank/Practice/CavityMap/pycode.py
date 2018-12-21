import sys
sys.setrecursionlimit(2000)
from collections import Counter
# sys.stdin.readline()

if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]
    a = [[int(val) for val in input().replace(" ", '')] for row in range(n)]

    cavities = []
    for row in range(n):
        for col in range(n):
            if (row == 0 or col == 0 or row == n-1 or col == n-1):
                continue    
            val = a[row][col]
            if(val > a[row-1][col] and val > a[row+1][col] and 
                val > a[row][col-1] and val > a[row][col+1]):
                cavities.append((row, col))


    for row, col in cavities:
        a[row][col] = 'X'

    for row in a:
        for col in row:
            print(str(col), end='')
        print('') 
      
 
