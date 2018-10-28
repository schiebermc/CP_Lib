# use this as the main template for python problems
from collections import Counter
import sys
sys.setrecursionlimit(50000)

def solution(a, b):
    
    saved = {}
    ind1 = len(a)
    ind2 = len(b)
    #while(ind1 >= 1 and ind2 >= 1):
    #    best_from_here(a, b, ind1, ind2, saved)
    #count = best_from_here(a, b, 0, 0, len(a), len(b), saved)
    #count = best_from_here(a, b, 0, 0, len(a), len(b), saved)
    C = [[0 for val in range(ind1+1)] for row in range(ind2+1)]
    for i in range(1, ind1+1):
        for j in range(1, ind2+1):
            if(a[i-1] == b[j-1]):
                C[i][j] = C[i-1][j-1] + 1
            else:
                C[i][j] = max(C[i][j-1], C[i-1][j])
    print(C[ind1][ind2])
    #print(count)


def best_from_here(a, b, i, j, na, nb, saved):

    if((i, j) in saved):
        return saved[(i, j)]

    if(i == na or j == nb):
        return 0   

    count1 = 0
    count2 = 0
    count3 = 0
    if(a[i] == b[j]):
        count1 = 1 + best_from_here(a, b, i+1, j+1, na, nb, saved)

    else:
        count2 = best_from_here(a, b, i+1, j, na, nb, saved)
        count3 = best_from_here(a, b, i, j+1, na, nb, saved)
   
     
    #ans = count1 if count1 > count2 else count2
    #ans = ans if ans > count3 else count3
    ans = max(count1, count2, count3)
    saved[(i, j)] = ans
    return ans

#def best_from_here(a, b, i, j, na, nb, saved):
#
#    if((i, j) in saved):
#        return saved[(i, j)]
#
#    if(i == na or j == nb):
#        return 0   
#
#    count1 = 0
#    count2 = 0
#    count3 = 0
#    if(a[i] == b[j]):
#        count1 = 1 + best_from_here(a, b, i+1, j+1, na, nb, saved)
#
#    else:
#        count2 = best_from_here(a, b, i+1, j, na, nb, saved)
#        count3 = best_from_here(a, b, i, j+1, na, nb, saved)
#   
#     
#    #ans = count1 if count1 > count2 else count2
#    #ans = ans if ans > count3 else count3
#    ans = max(count1, count2, count3)
#    saved[(i, j)] = ans
#    return ans
    
 
if __name__ == "__main__":

    # single variables
    n = [str(val) for val in raw_input().split()][0]
    s = [str(val) for val in raw_input().split()][0]
    solution(n, s)

