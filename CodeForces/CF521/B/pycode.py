# use this as the main template for python problems
from collections import Counter

def solution(n, a):

    count = 0
    ind = 1
    while(ind < n-1):
        if(a[ind] == 0 and a[ind-1] == 1 and a[ind+1] == 1):
            a[ind+1] = 0
            ind = 1
            count += 1 
        ind += 1
    print(count)

if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]

    # vectors
    arr = [int(val) for val in input().split()]

    # solve it!
    solution(n, arr)
