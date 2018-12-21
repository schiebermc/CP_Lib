import sys
sys.setrecursionlimit(2000)
from collections import Counter
import math
from functools import reduce

def calculate_protrusion(h, w, a, row1, col1, row2, col2):
    if(row2 < 0 or row2 >= h or col2 < 0 or col2 >= w):
        return a[row1][col1]
    else:
        diff = a[row1][col1] - a[row2][col2]
        return max(diff, 0)
        

if __name__ == "__main__":

    # single variables
    h, w = [int(val) for val in input().split()]
    a = [[int(val) for val in input().split()] for x in range(h)]

    tots = h*w*2
    for row in range(h):
        for col in range(w):
            prot1 = calculate_protrusion(h, w, a, row, col, row+1, col)
            prot2 = calculate_protrusion(h, w, a, row, col, row-1, col)
            prot3 = calculate_protrusion(h, w, a, row, col, row, col+1)
            prot4 = calculate_protrusion(h, w, a, row, col, row, col-1)
            cont = prot1 + prot2 + prot3 + prot4
            tots += cont
    print(tots)

