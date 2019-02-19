import sys
sys.setrecursionlimit(2000)
from collections import Counter


def solution1(s):
    freqs = sorted([val for key, val in Counter(s).items()], reverse=True)
    summ = sum(freqs)        
    flagged = False 
    best = float('inf')
    for nletters in range(1, len(freqs)+1):
        if(summ % nletters != 0): 
            continue
        cost = 0
        each = summ / nletters
        for to_fill in range(0, nletters):
            val = freqs[to_fill]
            if(val > each):
                flagged = True
                cost += abs(freqs[to_fill] - each)
        cost += sum(freqs[nletters:])
        best = min(cost, best)
    return int(best)


def solution2(s):
    freqs = sorted([val for key, val in Counter(s).items()], reverse=True)
    diff = 26 - len(freqs)
    freqs += [0]*diff
    summ = sum(freqs)        
    best = float('inf')
    for nletters in range(1, len(freqs)+1):
        if(summ % nletters != 0): 
            continue
        cost = 0
        each = summ / nletters
        for to_fill in range(0, nletters):
            val = freqs[to_fill]
            if(val > each):
                cost += abs(freqs[to_fill] - each)
        cost += sum(freqs[nletters:])
        best = min(cost, best)
    return int(best)


def validate():
    import string
    import random
    N = 18
    random.seed(0) 
    for i in range(10):
        s = ''.join(random.choice(string.ascii_uppercase) for _ in range(N))
        assert solution1(s) == solution2(s)


if __name__ == "__main__":

    #validate()

    t = [int(val) for val in input().split()][0]

    for test in range(t):
        s = input()
    
        print(solution2(s))



