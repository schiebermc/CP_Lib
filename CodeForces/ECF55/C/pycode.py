import sys
sys.setrecursionlimit(2000)
from collections import Counter

if __name__ == "__main__":

    # single variables
    n, m = [int(val) for val in input().split()]

    delagates = {}

    for i in range(n):
        
        s, r = [int(val) for val in input().split()]
    
        if(s in delagates):
            delagates[s].append(r)
        else:
            delagates[s] = [r]


    summs = {}
    for key in delagates:
        delagates[key].sort(reverse=True)
        summ = 0
        for i in range(1, len(delagates[key])+1):
            summ += delagates[key][i-1]
            if(summ < 0):
                continue
            if(i in summs):
                summs[i] += summ
            else:
                summs[i] = summ
 
    
    summs[-1] = 0
    best = max([val for key, val in summs.items()])
    print(max(best, 0))


