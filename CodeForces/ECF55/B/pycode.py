import sys
sys.setrecursionlimit(2000)
from collections import Counter


def solution(n, a):

    new_a = []
    # do one level of contraction
    summ = 0
    for i in a:
        summ += i
        if(i == 0):
            if(summ != 0):
                new_a.append(summ)
            new_a.append(i)
            summ = 0

    if(summ != 0):
        new_a.append(summ)

#    print(a)
    a = new_a
#    print(a)

    # index the gold patches
    gind = 0
    golds = {}
    edges = []
    for ind, val in enumerate(a):
        if(val != 0):
            golds[gind] = val
            gind += 1
        else: # test for bridge
            if(ind != 0 and a[ind-1] != 0 and
                ind != len(a)-1 and a[ind+1] != 0):
                edges.append([gind-1, gind])

#    print(golds)
#    print(edges)

    # golds index each patch of gold
    # edges contain edgs where a gold can meet another gold patch
    best = 0
    if(len(edges) != 0): # there is at least two gold patches, and they connect
    
        for ind1, ind2 in edges:
        
            val = golds[ind1] + golds[ind2] 
            if(len(golds) > 2):
                val += 1
            best = max(best, val)

        
    if(len(golds) == 0):
        val = 0
    else:
        val = max([val for key, val in golds.items()])
        if(len(golds) != 1):
            val += 1

    best = max(best, val)

    print(best) 
    return best

#from random import seed
#from random import randint
#def validate():
#
#    for s in range(10):
#        
#        seed(s)
#        a = [randint(0, 1) for i in range(10)]
#        val1 = solution(len(a), a)
#
#        print(a, val1)
        

if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]

    # vectors
    a = [1 if val == 'G' else 0 for val in input()]

    # solve it!
    solution(n, a)

#    validate()


