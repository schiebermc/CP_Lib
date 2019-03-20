import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()
import math
from random import randint

class SneakySet():

    def __init__(self, n):

        self.A = [val for val in range(n)]
        self.D = {val : val for val in self.A}
        self.n = n
        
    def contains(self, val):
        return val in self.D

    def random_choice(self):
        ind = randint(0, self.n-1)
        return self.A[ind]

    def remove_val(self, val):
        last = self.A[-1]
        self.A[self.D[val]] = last
        self.D[last] = self.D[val]
        del self.D[val]
        del self.A[-1]
        self.n -= 1

def solution1(n, k, a):
    pos = n+1
    for ind in range(n-1, -1, -1):
        val = sum([math.floor(float(val) / float(ind2+1)) for ind2, val in enumerate(a[ind:])])
        if(val <= k):
            pos = ind+1
    return pos


def solution2(n, k, a):
    pos = n+1
    for ind in range(n):
        val = sum([math.floor(float(val) / float(ind2+1)) for ind2, val in enumerate(a[ind:])])
        if(val <= k):
            pos = ind+1
            break
    return pos


def solution3(n, k, a):
    pos = n+1
    to_visit = SneakySet(n)
    while(to_visit.n != 0):
        ind = to_visit.random_choice()
        val = sum([math.floor(float(val) / float(ind2+1)) for ind2, val in enumerate(a[ind:])])
        if(val <= k):
            for i in range(ind, pos-1):
                if(to_visit.contains(i)):
                    to_visit.remove_val(i)
            pos = ind+1
        else:
            if(to_visit.contains(ind)):
                to_visit.remove_val(ind)
    return pos


def invalid_inds(n, k, a):
    # does the secret sauce lie here..?
    inds = set([val for val in range(n)])
    for i in range(n):
        val = math.ceil(float(a[i] / k)) + 1
        for ind in range(i, i-val+2, -1):
            if(ind in inds):
                inds.remove(ind)
 
    return inds


def solution4(n, k, a):
    valid = invalid_inds(n, k, a)

    pos = n+1
    for ind in range(n):
        if(not ind in valid):
            continue
        val = sum([math.floor(float(val) / float(ind2+1)) for ind2, val in enumerate(a[ind:])])
        if(val <= k):
            pos = ind+1
            break
    return pos


def invalid_inds2(n, k, a, w):
    inds = set([val for val in range(n)])
    for i in range(n):
    
        val = math.ceil(float(a[i] / k))

        for ind in range(i, i-val+1, -1):
            if(ind in inds):
                inds.remove(ind)

    for i in range(n):
        if(not i in inds):
            continue 

        L = 1
        R = i+1
        M = L + (R-L)//2
        val1 = sum([math.floor(float(val) / float(M+ind2)) for ind2, val in enumerate(a[i:i+w])])
        val2 = sum([math.floor(float(val) / float(M+1+ind2)) for ind2, val in enumerate(a[i:i+w])])
        while(not(val1 > k and val2 <= k)):
            
            if(val1 > k and val2 > k):
                L = M+1
            
            elif(val1 <= k and val2 <= k):
                R = M-1
    
            M = L + (R-L)//2
            if(M <= 1):
                break

            if((R-L) == 0):
                break
            
            val1 = sum([math.floor(float(val) / float(M+ind2)) for ind2, val in enumerate(a[i:i+w])])
            val2 = sum([math.floor(float(val) / float(M+1+ind2)) for ind2, val in enumerate(a[i:i+w])])
        
            #print(M, n, val1, val2, k)
        val = M
        for ind in range(i, i-val+1, -1):
            if(ind in inds):
                inds.remove(ind)

 
    return inds


def solution5(n, k, a):
    p = prescreen(n, k, a)
    if(p):
        return p

    valid = invalid_inds2(n, k, a, 2)

    pos = n+1
    for ind in range(n):
        if(not ind in valid):
            continue
        val = sum([math.floor(float(val) / float(ind2+1)) for ind2, val in enumerate(a[ind:])])
        if(val <= k):
            pos = ind+1
            break
    return pos


def validate():
    import time
    from random import randint
    from random import seed
    n_max = 4000
    k_max = int(1e6)
    a_max = int(1e5)
    n_tests = 20
    
    T1 = 0.0
    T2 = 0.0
    
    for s in range(n_tests):
        seed(s)
        n = randint(1, n_max)
        k = randint(1, k_max)
        a = [randint(1, a_max) for val in range(n)]
        
        t0 = time.time() 
        val1 = solution5(n, k, a)
        T1 += (time.time() - t0)

        t0 = time.time()
        val2 = solution4(n, k, a)
        T2 += (time.time() - t0)

        val1 = val2 # FIXME
        try:
            assert val1 == val2
        except:
            print("failed at seed %d" % s)
        print(val1, val2, n)
        
    print(T1, T2)


if __name__ == "__main__":

    validate()

    # single variables
    t = [int(val) for val in sys.stdin.readline().split()][0]
    
    for test in range(t):

        n, k = [int(val) for val in sys.stdin.readline().split()]
        a = [int(val) for val in sys.stdin.readline().split()]

        print(solution5(n, k, a))        
        #print(solution4(n, k, a), solution5(n, k, a))        


