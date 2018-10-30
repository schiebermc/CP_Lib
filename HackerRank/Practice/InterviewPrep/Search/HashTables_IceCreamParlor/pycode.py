# use this as the main template for python problems
from collections import Counter

def solution(m, n, a):

    c = {}
    for ind, i in enumerate(a):
        if(i in c):
            c[i].append(ind+1)
        else:
            c[i] = [ind+1]

    for i in c:
        if ((m - i) in c):
            ind1 = c[i][0]
            if(m - i - i == 0):
                ind2 = c[i][1]
            else:
                ind2 = c[m-i][0]
            break
    if(ind1 < ind2):
        print(ind1, ind2)
    else:     
        print(ind2, ind1)



if __name__ == "__main__":

    # single variables
    t = [int(val) for val in input().split()][0]
    for i in range(t):

        m = [int(val) for val in input().split()][0]
        n = [int(val) for val in input().split()][0]
        arr = [int(val) for val in input().split()]
    
        # solve it!
        solution(m, n, arr)
    
