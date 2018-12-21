import sys
from collections import Counter
def brute_force(n, m, a):
    # BAKA! very easy problem once one realizes
    # the contraints of expenditures[i] <= 200
    # therefore, counting sort may be invoked
    count = 0
    counts = [0] * 201
    for i in range(n):

        if(i != 0):
            counts[a[i-1]] += 1    
            
        if(i < m):
            continue

        median = get_median_from_counts(counts, m)
        #s = sorted(a[i-m:i])
        #median2 = (s[m//2-1]+s[m//2])/2.
        #print(s[m//2-1], s[m//2], s[m//2+1], m//2) 
        #print(i, median, median2)
        #if(median != median2):
        #    raise Exception()
        if(a[i] >= 2*median):
            count += 1

        counts[a[i-m]] -= 1
    
    print(count)


def get_median_from_counts(counts, m):
 
    ind = 0
    count = 0
    val1 = None
    while(count < m//2+1):
        count += counts[ind]
        if(val1 == None and count >= m//2):
            val1 = ind
        if(count >= m//2+1):
            val2 = ind
        ind += 1

    if(m % 2 == 1):
        return val2
    else:
        return (val1 + val2) / 2.


if __name__ == "__main__":

    # single variables
    n, m  = [int(val) for val in input().split()]

    # vectors
    a = [int(val) for val in input().split()]

    # solve it!
    brute_force(n, m, a)



