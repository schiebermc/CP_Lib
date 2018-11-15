# use this as the main template for python problems
from collections import Counter

def solution(n, arr):
    arr = [0] + arr
    arr.append(1001)
    
    best = 0
    count = 0
    for ind, val in enumerate(arr[:-2]):
        if(val+1 == arr[ind+1] and (val+2 == arr[ind+2])):
            count += 1
        else:
            if(best < count):
                best = count
            count = 0
    print(max(best, count))


if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]

    # vectors
    arr = [int(val) for val in input().split()]

    # solve it!
    solution(n, arr)

