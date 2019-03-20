import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()



if __name__ == "__main__":

    # single variables
    t = [int(val) for val in sys.stdin.readline().split()][0]

    for i in range(t):

        n = [int(val) for val in sys.stdin.readline().split()][0]
        a = [int(val) for val in sys.stdin.readline().split()]

        poss = 0
        negs = 0
        zers = 0
        for val in a:
            if(val > 0):
                poss += 1
            elif(val < 0):
                negs += 1
            else:
                zers += 1

        if(negs == 0):
            if(zers == 0):
                print(poss, poss)
            else:
                print(poss+zes, min(poss, zers))
        
        elif(poss == 0):
            if(zers == 0):
                print(negs, negs)
            else:
                print(negs+zes, min(negs, zers))
            
        else:
            if(zers == 0):
                print(max(poss, negs), min(poss, negs)) 
            else:
                print(max(poss+zers, negs+zers), min(poss, negs, zers)) 
 
    
