# use this as the main template for python problems
from collections import Counter

def solution(n, k, a):

    c = Counter(a)
    counts = [[val, key, 1, val] for key, val in c.items()]
    counts.sort(key=lambda x: x[0], reverse=True)

    #ind = 0
    #tots = 0   
    #while(tots < k):
    #    print(tots, k)
    #    print(counts, tots, k)
    #    replaced = False
    #    while(ind+1 < len(counts) and (counts[ind][0] / (counts[ind][2]*2)) >= (counts[ind+1][0] / counts[ind+1][2]) and
    #            counts[ind+1][0] != 1): 
    #        val, key, count, count2 = counts[ind]
    #        counts[ind] = [val, key, count*2, val // (count*2)]
    #        replaced = True
    #    
    #    if(tots == len(counts)):
    #        val, key, count, count2 = counts[0]
    #        counts[0] = [val, key, count*2, val // (count*2)]
    #        counts.sort(key=lambda x: x[3], reverse=True)
    #        ind = 0
    #        tots = 0
 
    #    elif(replaced):
    #        tots = 0
    #        ind = 0
    #    
    #    else:
    #        tots += counts[ind][2]
    #        ind += 1
    if(len(counts) == 1):
        for i in range(k):
            print("%d " % a[0], end=' ')
        print('')    
        return   
 
    tots = 0
    ind = 0
    included = []
    while(tots < k):

        tots = 0
        replaced = False
        for ind1, val1 in enumerate(included):
            for ind2, val2 in enumerate(included[ind1+1:]):
                if(tots >= k or replaced):
                    break
                if(val1[3]/2 > val2[3]):
                    val, key, count, count2 = val1
                    included[ind1] = [val, key, count*2, val//(count*2)]
                    replaced = True
            
            if(tots >= k or replaced):
                break
            
            tots += val1[2]      

        print(tots)
        if(tots < k and ind == len(counts)):
            val, key, count, count2 = included[0]
            included[0] = [val, key, count*2, val//(count*2)]
            included.append(included[0])
            del included[0]
 
        elif(tots < k and not replaced):
            included.append(counts[ind])
            ind += 1

        included.sort(key=lambda x: x[3], reverse=True)

    included.sort(key=lambda x: x[0], reverse=True)
    ans = []
    ind = 0
    while(len(ans) < k):
        for i in range(included[ind][2]):
            if(len(ans) == k):
                break
            ans.append(included[ind][1])
        ind += 1 
    for i in ans:
        print("%d " % i, end='')
    print('')
 

def validate():
    from random import randint
    n = int(2*1e5)
    k = int(2*1e5)
    a = [randint(1, 10000) for i in range(n)]
    solution(n, k, a)    


if __name__ == "__main__":

    # single variables
    n, k = [int(val) for val in input().split()]

    # vectors
    arr = [int(val) for val in input().split()]

    validate()

    # solve it!
    #solution(n, k, arr)


