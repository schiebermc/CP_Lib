# use this as the main template for python problems
from collections import Counter

def solution(n, a, k):

    # strat 1. go by contenders.  
    # go level by level. 
    # turn anything that is not an a into an a
    # keep track of how many a's a path has used.
    # kill off anything that is not a tie
    # terminate at the botom right 

    # initial algo is correct, but uses too much memory
    # to avoid blow up of contendres, use a dictionary
    # which will merge on key (tots, i, j)
    # actually need to levels of hashing - {tots : {(i, j) : path}}
    # liberally eliminate anything other than tots after each iter

    # update old algo may have been fine, if I pruned previously lenghts....

    if(a[0][0] == 1):
        contenders = {(1, 0, 0) : ([1], 1, 0, 0, 0)}
    elif(k != 0):
        contenders = {(1, 0, 0) : ([1], 1, 1, 0, 0)}
    else:   
        val = a[0][0]
        contenders = {(1, 0, 0) : ([val], val, 0, 0, 0)}

    done = False
    while(not done):
        new_contenders = {}
        best = float('inf')
        for info, c in contenders.items():
            for path in go_from_here(c, a, n, k):
                val = path[1]
                if(val < best):
                    best = val
                if(val == best):
                    new_contenders[(val, path[3], path[4])] = path                    
                            
        #eliminate contenders that were not perfect
        to_delete = [val for val in new_contenders if val[0] != best]
        for val in to_delete:
            del new_contenders[val] 
        contenders = new_contenders
        
        i, j = next(iter(contenders.values()))[3:]
        if(i+1 == n and j+1 == n):
            done = True
   
    for i in next(iter(contenders.values()))[0]:
        print(chr(i + 96), end='')
    print('')    


def go_from_here(c, a, n, k):
    i, j = c[3:]
   
    if(i+1 != n): # try to go down
        val = a[i+1][j]
        if(val == 1):
            yield (c[0] + [1], c[1]+1, c[2], i+1, j)
        else:
            if(c[2] != k):
                yield (c[0] + [1], c[1]+1, c[2]+1, i+1, j)
            else:
                yield (c[0] + [val], c[1]+val, c[2], i+1, j)
                
    if(j+1 != n): # try to go right
        val = a[i][j+1]
        if(val == 1):
            yield (c[0] + [1], c[1]+1, c[2], i, j+1)
        else:
            if(c[2] != k):
                yield (c[0] + [1], c[1]+1, c[2]+1, i, j+1)
            else:
                yield (c[0] + [val], c[1]+val, c[2], i, j+1)


if __name__ == "__main__":

    # single variables
    n, k = [int(val) for val in input().split()]

    # vectors
    a = [[ord(val) - 96 for val in input()] for i in range(n)]

    # solve it!
    solution(n, a, k)

