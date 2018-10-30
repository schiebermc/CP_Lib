# use this as the main template for python problems
from collections import Counter

def solution(n, a):

    count = 0
    ind = 0
    while(ind != n-1):
        if(ind+2 < n and a[ind+2] == 0):
            ind += 2
        else:
            ind += 1
        count += 1
    print(count)

if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]

    # vectors
    arr = [int(val) for val in input().split()]

    # solve it!
    solution(n, arr)



