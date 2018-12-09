import sys

def compute_and_print(R, L):
    bump = abs(R - L) // 10
    M = min(R, L + bump)
    print("1 %d" % (M))   
    sys.stdout.flush()
    return M

if __name__ == "__main__":

    # get variables
    n, c = [int(val) for val in input().split()]

    # set up binary search (kind of)
    R = n
    L = 1
    cost = 0
    coins = 1000

    # print first attempt
    M = compute_and_print(R, L) 

    largers = set([])
    smallers = set([])

    # loop until correct
    while(cost < coins):
        
        # the network is assumed to be fixed before the previous print
        result = [int(val) for val in input().split()][0]

        if(result == 1): # too high
            largers.add(M)
            if(M-1 in smallers):
                L = M
                R = M
            else:
                R = min(R-1, M)

        else: 
            smallers.add(M)
            if(M+1 in largers):
                R = M+1
                L = M+1
            else:
                L = M+1 if L == M else M
                    

        if(R == L):
            break
        
        if(result == 1):
            cost += c
            print("2")   
            sys.stdout.flush()
           
        M = compute_and_print(R, L) 

#    print(cost)
    if(result == 1):
        print("2")
    print("3 %d" % (R))   
    sys.stdout.flush()



