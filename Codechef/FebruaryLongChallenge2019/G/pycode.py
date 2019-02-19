import sys
sys.setrecursionlimit(2000)
from collections import Counter
from fractions import Fraction

def gcd_extended(a, b, x, y):
# C function for extended Euclidean Algorithm (used to 
# find modular inverse. 
    if (a == 0):
        x[0] = 0
        y[0] = 1 
        return b 
    x1 = [0]
    y1 = [0]
    gcd = gcd_extended(b%a, a, x1, y1)
    x[0] = y1[0] - (b//a) * x1[0]
    y[0] = x1[0] 
    return gcd


def mod_inverse(b, m):
# Function to find modulo inverse of b. It returns 
# -1 when inverse doesnt 
    x = [0]
    y = [0]
    g = gcd_extended(b, m, x, y) 
    if (g != 1):
        return -1 
    return (x[0]%m + m) % m; 


def mod_divide(a, b, m):
# Function to compute a/b under modlo m 
    a = a % m
    inv = mod_inverse(b, m) 
    if (inv == -1): 
        raise Exception()
    return (inv * a) % m


def solution(N, K, M, modval):
    carry = Fraction(1, 1)
    f = Fraction(0, 1)
    for move in range(M):
        
        # chef makes a guess
        if(move == M-1 or N < K):
            f += carry * Fraction(1, N)
            carry *= Fraction(N-1, N)
            N += K

        # remove some of the mcshizzle, for rizzle
        else:
            N = N % K

    return mod_divide(f.numerator, f.denominator, modval)

def solution(N, K, M, modval):
    carry = Fraction(1, 1)
    f = Fraction(0, 1)
    for move in range(M):
        
        # chef makes a guess
        if(move == M-1 or N < K):
            f += carry * Fraction(1, N)
            carry *= Fraction(N-1, N)
            print(carry)
            N += K

        # remove some of the mcshizzle, for rizzle
        else:
            N = N % K

    return mod_divide(f.numerator, f.denominator, modval)

def solution2(N, K, M, modval):
    carry_num = 1
    carry_den = 1
    P = 0
    Q = 1
    f = Fraction(0, 1)
    for move in range(M):
        
        # chef makes a guess
        if(move == M-1 or N < K):
            f += carry * Fraction(1, N)
            carry *= Fraction(N-1, N)
            N += K

        # remove some of the mcshizzle, for rizzle
        else:
            N = N % K

    return mod_divide(f.numerator, f.denominator, modval)


if __name__ == "__main__":
    modval = int(1e9+7)

    from random import randint
    from time import time
    t0 = time()
    for i in range(5):
        N = randint(1, 3e4-1)
        K = randint(N+1, 3e4)
        M = randint(1, 3e4)
        print(solution(N, K, M, modval))
    t1 = time()
    print(t1 - t0)
    
    t = [int(val) for val in input().split()][0]
    
    for test in range(t):
    
        N, K, M = [int(val) for val in input().split()]
        print(solution(N, K, M, modval))

        

