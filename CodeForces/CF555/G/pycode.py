import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()

def get_info(row):
    s = set(row)
    if(len(s) == 1):
        homogeneous = True
    else:
        homogeneous = False
    is_sorted = True
    for ind, val in enumerate(row[1:]):
        if(val < row[ind]):
            is_sorted = False
    is_reverse_sorted = True
    for ind in range(n-1, 1, -1):
        if(row[ind-1] > row[ind]):
            is_reversed_sorted = False
    return (homogeneous, is_sorted, 0 in s, 1 in s, is_reverse_sorted)

def mc(A, col):
    for row in A:
        row[col] = 1 - row[col]

def mr(A, row):
    for ind, val in enumerate(A[row]):
        A[row][ind] = 1 - A[row][ind]

def is_pos(A, flip, start_row, end_row, rows, cols):
    pos = True
    for row in range(start_row, end_row+1):
        info = get_info(A[row])
        if(info[0]):
            must_b = '0' if not flip else '1'
            if(must_b == '0'):
                if(info[2]):
                    pass
                else:
                    mr(A, row)
                    rows[row] = '1'
            else:
                if(info[3]):
                    pass
                else:
                    mr(A, row)
                    rows[row] = '1'
        else:
            if(flip):
                pos = False
                break
            elif(info[1]):
                flip = True
            elif(info[4]):
                mr(A, row)
                rows[row] = '1'
                flip = True
            else:
                pos = False
                break
    return pos        
 
def force_row_to_val(A, row, val, rows, cols):
    info = get_info(A[row])
    check_ind = 2 if val == 1 else 3
    if(info[0]):
        if(info[check_ind]):
            mr(A, row)
            rows[row] = '1'
        else:
            pass
    else:
        for i in range(m):
            if(A[row][i] != val):
                mc(A, i)
                cols[i] = '1'


if __name__ == "__main__":

    # single variables
    n, m = [int(val) for val in sys.stdin.readline().split()]
    A = [[int(val) for val in sys.stdin.readline().split()] for row in range(n)]

    # ans
    rows1 = ['0'] * n
    cols1 = ['0'] * m
    rows2 = ['0'] * n
    cols2 = ['0'] * m

    from copy import deepcopy
    A1 = deepcopy(A)
    A2 = deepcopy(A)

    force_row_to_val(A1, -1, 1, rows1, cols1) 
    pos1 = is_pos(A1, False, 0, n-2, rows1, cols1)
    
    force_row_to_val(A2, 0, 0, rows2, cols2) 
    pos2 = is_pos(A2, False, 1, n-1, rows2, cols2)

    if(pos1):
        cols = cols1
        rows = rows1
    elif(pos2):
        cols = cols2
        rows = rows2

    if(pos1 or pos2):
        print("YES")
        for val in rows:
            print(val, end='')
        print("")
        for val in cols:
            print(val, end='')
        print("")
    else:
        print("NO")





