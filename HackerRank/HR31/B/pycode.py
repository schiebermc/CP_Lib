import sys
sys.setrecursionlimit(2000)
from collections import Counter
from time import sleep

if __name__ == "__main__":

    # single variables
    n, k = [int(val) for val in input().split()]
    a = [int(val) for val in input().split()]


    if(n == k):
        print(min(a))

    else:

        a.sort()
        rem = sum(a[:k-n])
        a = a[k-n:]
        best = min(a)

        val = a[0]
        count = 0
        while(count != n):
       
            while(count < n and a[count] == val):
                count += 1
    
            if (count == n):
       
                bump = rem / count
            
            else:

                next_val = a[count]     
                diff = next_val - val
                if(count*diff > rem):
                    bump = rem / count  
                    count = n
                else:
                    bump = diff    
                           
            val += bump
            rem -= bump * count
            best += bump

    print(best)



    
