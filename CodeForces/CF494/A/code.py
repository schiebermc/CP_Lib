from collections import Counter


def solution(arr, n):

    d = Counter(arr)
    best = 0
    for key, val in d.items():
        if(val > best):
            best = val
    print (best)

if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()]

    # vectors
    arr = [int(val) for val in input().split()]

    # solve it!
    solution(arr, n)



