import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()

if __name__ == "__main__":

    # single variables
    t = [int(val) for val in sys.stdin.readline().split()][0]

    for test in range(t):

        N, d = [int(val) for val in sys.stdin.readline().split()]
        # 1. N cannot change with respect to how many digits it has
        # 2. the smallest N will have the smallest n_i in the left position.
        # recurse untile the last digit
        N = [int(val) for val in str(N)]
        #print(N)

        for ind in range(len(N)):
           
            minn = min(min(N[ind:]), d)
            
            if(minn == N[ind]):
                continue
            
            else:
                
                minn_ind = 0
                while(ind+minn_ind != len(N) and minn != N[ind+minn_ind]):
                    minn_ind += 1
            
                new_N = N[:ind] + N[ind+minn_ind:]
                for count in range(minn_ind):
                    new_N.append(d)

                N = new_N

        for val in N:
            print(val, end='')
        print('')
        
 

        

