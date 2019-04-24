from collections import Counter


def solution(arr, n, q):

    d = Counter(arr)
    a = [key for key in d]
    a.sort(reverse=True)
    for query in range(q):
        b = [int(val) for val in input().split()][0]
        print(get_min_number(d, b, a))


def get_min_number(d, b, a):
    count = 0
    coins = 0
    for val in a:
        if(count == b):
            break
        
        c = (b - count) // val
        coins += c
        count += c * val

    if(count == b):
        return coins
    else:
        return -1

if __name__ == "__main__":

    # single variables
    n, q = [int(val) for val in input().split()]

    # vectors
    arr = [int(val) for val in input().split()]

    # solve it!
    solution(arr, n, q)



