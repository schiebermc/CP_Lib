import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
import math

def solution1(N, K, A):
    
    X = None
    F = None
    count = 0
    for l in range(N):
        for r in range(l, N):
            c = Counter(A[l:r+1])
            m = math.ceil(float(K)/float(r - l + 1))

            ind2 = 0
            for key, val in sorted(c.items(), key=lambda x: x[0]):
                if(ind2 + val * m >= K):
                    X = key
                    break
                ind2 += val * m   
           
            F = c[X] if X in c else 0
            count += 1 if F in c else 0            
           
    return count 


def solution2(N, K, A):

    X = None
    F = None
    count = 0
    for l in range(N):
        for r in range(l, N):
            
            c = [0] * 2000
            for val in A[l:r+1]:
                c[val-1] += 1

            ind2 = 0
            m = math.ceil(float(K)/float(r - l + 1))
            for key, val in enumerate(c):
                if(ind2 + val * m >= K):
                    X = key
                    break
                ind2 += val * m   
            
            X += 1           
            F = c[X-1]
            if(F == 0):
                continue
            count += bool(int(c[F-1]))
 
    return count 


def solution3(N, K, A, d1, d2):

    X = None
    F = None
    count = 0
   
    c = [0] * 2000
    assert d1*d2 == 2000    
    jumps = [0]*d1 

    for l in range(N):
        for r in range(l, N):

            c[A[r]-1] += 1
            jumps[(A[r]-1)//d2] += 1            

            m = math.ceil(float(K)/float(r - l + 1))

            ind2 = 0
            jump = 0
            for key, val in enumerate(jumps):
                if(ind2 + val * m >= K):
                    jump = key
                    break
                ind2 += val * m   
         
            for key, val in enumerate(c[jump*d2:(jump+1)*d2]):
                if(ind2 + val * m >= K):
                    X = key + (jump*d2)
                    break
                ind2 += val * m   
            
            X += 1           
            F = c[X-1]
            if(F == 0):
                continue
            count += bool(int(c[F-1]))

        for r in range(l, N):
            c[A[r]-1] -= 1 
            jumps[(A[r]-1)//d2] -= 1            
    
    return count 


def get_frequency(n, c, l, r):
    # frequency at r           
    if(n == 0):
        freq = c[r][n]
    else:
        freq = c[r][n] - c[r][n-1]
 
    # frequency to the left of l
    if(l != 0):
        if(n == 0):
            freq -= c[l-1][n]
        else:
            freq -= (c[l-1][n] - c[l-1][n-1])
    
    return freq

def solution4(N, K, A):

    count = 0
    max_A = max(A)

    # c will be N * max_A
    c = [[0]*max_A]
    for r in range(A[0]-1, max_A):
        c[0][r] += 1

    for l in range(1, N):
        val = A[l]-1
        c.append([c[l-1][r] for r in range(max_A)]) 
        for r in range(val, max_A):
            c[l][r] += 1

    f = [[0]*max_A]
    f[0][A[0]-1] += 1
    for l in range(1, N):
        f.append([f[l-1][r] for r in range(max_A)])
        f[l][A[l]-1] += 1 

    print(c)
    print(f)
    
    X = (max_A) // 2
    for size in range(1, N+1):
        m = math.ceil(float(K)/float(size))
        print("m---- ", m)
        for l in range(N-size+1):
            r = l + size - 1
            #X = find_X(l, r, m, K, c, max_A) 
            print([[l, r]])
            L = 0
            R = max_A-1
        
            M = X
            #M = X # use previous index to try and speed up
 
            if(l == 0):
                if(M != 0):    
                    val1 = (c[r][M-1])*m
                else:
                    val1 = 0
        
                val2 = (c[r][M])*m 
            else:
                if(M != 0):
                    val1 = (c[r][M-1]-c[l-1][M-1])*m 
                else:
                    val1 = 0
                val2 = (c[r][M]-c[l-1][M])*m 
        
            while(not (val1 < K and val2 >= K)):
        
                #print(val1, val2, K, M, l, r)
                print(M, max_A, val1, val2)   
                # we need to find exact M
                # if val1 and val2 are less than M, we certainly need to go up 
                if(val1 < K and val2 < K):
                    L = M+1
                else:
                    R = M-1
                
                M = L + (R - L) // 2
                    
                # HERE
                if(l == 0):
                    if(M != 0):    
                        val1 = (c[r][M-1])*m
                    else:
                        val1 = 0
        
                    val2 = (c[r][M])*m 
                else:
                    if(M != 0):
                        val1 = (c[r][M-1]-c[l-1][M-1])*m 
                    else:
                        val1 = 0
                    val2 = (c[r][M]-c[l-1][M])*m 
            
            X = M

            print("exit X : %d " % (X))
            F = f[r][X]
            if(l != 0):
                F -= f[l-1][X]            
            
            if(F == 0):
                continue
            if(F > max_A):
                continue
            
            v = f[r][F-1]
            if(l != 0):
                v -= f[l-1][F-1]            
            
#            print(size, A[l:r+1], "m: %d, K: %d,  X: %d, F: %d, val: %d" % (m, K, X, F, v), count)
            
            if(v > 0):
                count += 1    
    
    return count 


def validate():

    from random import seed
    from random import randint
    ntests = 5
    #N_max = 20
    #A_max = 20
    N_max = 2000
    A_max = 2000
    K_max = int(1e9)

    import time
    T1 = 0.0
    T2 = 0.0
    for test in range(ntests):
    
        seed(test)
        N = randint(1, N_max)
        K = randint(1, K_max)
        A = [randint(1, A_max) for val in range(N)]

        t0 = time.time() 
        #val1 = solution3(N, K, A, 40, 50)
        T1 += (time.time() - t0)

        t0 = time.time()
        val2 = solution4(N, K, A)
        T2 += (time.time() - t0)

        val1 = val2 #FIXME
        try:
            assert val1 == val2
        except:
            print("failed at seed %d" % test)
        print(val1, val2)


    print(T1, T2)


if __name__ == "__main__":
    
#    validate()

    t = [int(val) for val in sys.stdin.readline().split()][0]

    for test in range(t):

        N, K = [int(val) for val in sys.stdin.readline().split()]
        A = [int(val) for val in sys.stdin.readline().split()]
        
        print(solution4(N, K, A))
        
        


