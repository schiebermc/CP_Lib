import sys
from math import ceil

if __name__ == "__main__":

    n, s = [int(val) for val in input().split()]
    a = [int(val) for val in input().split()]
    total = sum(a)
    
    if(total < s):
        print("-1")
    else:

        summ = 0
        smallest = min(a)
        for i in a:
            summ += abs(smallest - i)

        if(summ >= s):
            pass

        else:
            diff = s - summ
            pours = int(ceil(float(diff) / float(n)))
            smallest -= pours   
 
        print(smallest)


