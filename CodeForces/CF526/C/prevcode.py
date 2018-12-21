import sys
from itertools import combinations

if __name__ == "__main__":

    # single variables
    s = [str(val) for val in input().split()][0]

    singles = 0
    for i in s:
        if(i == 'a'):
            singles +=1 

    count = 0
    groups = []
    for i in s:
        if(i == 'a'):
            count += 1
        if(i == 'b' and count != 0):
            groups.append(count)
            count = 0
    
    if(count != 0):        
        groups.append(count)
    
    ngroups = len(groups)
    tots = singles
    mod_val = int(1e9+7)
    for size in range(2, ngroups+1):
        for combo in combinations(groups, size):
            c = 1
            for i in combo:
                c = ((c % mod_val) * (i % mod_val)) % mod_val
            tots += c
            tots %= mod_val                       
    
    print(tots)

