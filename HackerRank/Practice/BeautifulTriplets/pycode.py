import sys
sys.setrecursionlimit(2000)

if __name__ == "__main__":

    # single variables
    n, d = [int(val) for val in input().split()]
    a = [int(val) for val in input().split()]
      
    ind1 = 0
    ind2 = 1 
    ind3 = 2

    count = 0
    while(ind1 != n and ind2 != n and ind3 != n):
        if(ind1 >= ind2):
            ind2 += 1
            continue
        
        if(ind2 >= ind3):
            ind3 += 1
            continue

        diff1 = a[ind2] - a[ind1]
        diff2 = a[ind3] - a[ind2]

        if(diff2 > d):
            ind2 += 1
            continue
    
        elif(diff2 < d):
            ind3 += 1
            continue
        
        else:
            pass
        
        if(diff1 > d):
            ind1 += 1
            continue
    
        elif(diff1 < d):
            ind2 += 1
            continue

        else:
            pass

        #print(a[ind1], a[ind2], a[ind3])
        count += 1
        ind1 += 1
    
    print(count)
    

    
