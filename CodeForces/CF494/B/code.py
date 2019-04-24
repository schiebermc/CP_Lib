from collections import Counter


def solution(a, b, x):

    n = a + b
    ac = n
    bc = 0
    
    try:
        s = [0] * n
        for i in range(b):
            s[i] = 1
        
        xc = 1
        shift = 0
        while(xc < x):
              
            if(xc < x-3):
                s[b-1-shift*2] = 0
                s[b+2+shift*2] = 1
                xc += 4
                shift += 1
                continue 
        
            if(xc < x-1):
                s[b-1-shift*2+1] = 0
                s[b+2+shift*2] = 1
                xc += 2
                continue
        
            if(xc == x-2):
                s[0] = 0
                s[n-1] = 1
                xc += 2
                continue
    
            if(xc == x-1):
                s[b-1-shift*2+1] = 0
                s[n-1] = 1
                xc += 1        
                continue
    except:
        pass

    print(s)
 
if __name__ == "__main__":

    # single variables
    a, b, x = [int(val) for val in input().split()]

    # solve it!
    solution(a, b, x)



