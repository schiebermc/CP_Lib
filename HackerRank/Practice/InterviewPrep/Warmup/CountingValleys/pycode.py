# use this as the main template for python problems
from collections import Counter

def solution(n, a):

    zeros = [0]
    print(n, a)
    levels = [0] * (n+1)
    for ind, val in enumerate(a):
        if(val == 'U'):
            levels[ind+1] = levels[ind] + 1
        elif(val == 'D'):
            levels[ind+1] = levels[ind] - 1
        
        if(levels[ind+1] == 0):
            zeros.append(ind+1)
        
    count = 0
    for zero in zeros[1:]:
        if(levels[zero-1] < 0):
            count += 1
    print(count)


if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]

    # vectors
    a = [str(val) for val in input().split()][0]

    # solve it!
    solution(n, a)

