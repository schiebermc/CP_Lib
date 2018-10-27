# use this as the main template for python problems
from collections import Counter

def brute_force(n, k, a):
    best = 0
    for i in range(n):
        length = None
        largers = set([])
        for j in range(i, n):
            if(a[j] > k):
                largers.add(a[j])
            if(len(largers) > 1):
                length = j - i
                break    
        if(length == None):
            length = n - i
        if(length > best):
            best = length
    return best


def solution(n, k, a):
    points = [-1]
    recent = None
    for ind, val in enumerate(a):
        if(val > k):
            if(recent == val):
                continue
            else:
                points.append(ind)
                recent = val

    points.append(n)
    best = 0
    for i in range(len(points)-2):
        if(i == len(points)-3):
            length = points[i+2] - points[i] - 2
        else:
            length = points[i+2] - points[i] - 1
        
        if length > best:
            best = length

    print(points)
    if(len(points) == 2):
        return len(a) 
    return best


def validation():
    import random

    N = 10
    for seed in range(100):
        random.seed(seed)
        arr = [random.randint(1, N) for i in range(N)]
        k = random.randint(1, N)
        val1 = brute_force(N, k, arr)
        val2 = solution(N, k, arr)

        if(val1 != val2):
            print("Failed at seed; ", seed, val1, val2, k, arr)
            raise Exception()


if __name__ == "__main__":

    # single variables
    T = [int(val) for val in input().split()][0]

    for i in range(T):
       
        n, k = [int(val) for val in input().split()]
        a = [int(val) for val in input().split()]
     
        validation()
        #print(brute_force(n, k, a))
        #print(solution(n, k, a))



