import sys
sys.setrecursionlimit(2000)
from collections import Counter


def solution(n, a):

    end_segs = {}
    before_segs = {}
    silvers = {}

    ind = 0
    count = 0
    new_a = []  
    for i in range(n):

        count += a[i]
        if(a[i] == 0 and count != 0):
       
            if(ind != 0): 
                before_segs[ind] = count
            silvers[i] = 1
            end_segs[i] = count
            count = 0

        if(a[i] == 0):
            ind = i

    if(count != 0):
        if(ind != 0): 
            before_segs[ind] = count
        silvers[n+1] = 0
        end_segs[n+1] = count

    #print(before_segs)
    #print(silvers)
    #print(end_segs)    

    if(len(end_segs) == 1):
        
        best = 0
        for i in end_segs:
            best = max(end_segs[i], best)

    elif(len(end_segs) == 2):
        
        # two cases, the two segments are more than 1 silver apart
        best = 0
        for i in end_segs:
            val = 0
            if(i in before_segs):
                val += before_segs[i] - 1
            val += silvers[i] + end_segs[i]
            best = max(val, best)

    else:
        
        best = 0
        for i in silvers:
            val = 0
            if(i in before_segs):
                val += before_segs[i]
            val += silvers[i] + end_segs[i]
            best = max(val, best)

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
#        

if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]

    # vectors
    a = [1 if val == 'G' else 0 for val in input()]

    # solve it!
    solution(n, a)

#    validate()


