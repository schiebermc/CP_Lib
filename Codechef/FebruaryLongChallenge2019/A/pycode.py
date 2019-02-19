import sys
sys.setrecursionlimit(2000)
from collections import Counter

def gcd(a, b):
    while b:
        a, b = b, a%b
    return a

def lcm(a, b):
    return (a*b)/gcd(a, b)


def validate():
    from random import randint
    from random import seed

    seed(0)
    
    for i in range(100):
        n = randint(1, 100)
        a = randint(1, n)
        b = randint(1, n)
        k = randint(1, n)
   
        #print(n, a, b, k)
        assert brute_force(n, a, b, k) == solution(n, a, b, k)
 
def brute_force(n, a, b, k):
    c1 = 0
    c2 = 0
    for i in range(1, n+1):
        if(i % a == 0 and i % b == 0):
            continue
        elif(i % a == 0):
            c1 += 1
        elif(i % b == 0):
            c2 += 1

    #print("Brute force c1, c2 : %d %d" % (c1, c2))
    if(c1 + c2 >= k):
        return True
    else:
        return False


def solution(n, a, b, k):
    c1 = n // a
    c2 = n // b

    if(a == b):
        c1 = 0
        c2 = 0
        c3 = 0
    else:
        c3 = n // ((a * b) / gcd(a, b))
    
    #print("Solution : %d %d %d" % (c1, c2, c3))
    if(c1 + c2 - 2*c3 >= k):
        return True
    else:
        return False


if __name__ == "__main__":
#    validate()
    t = [int(val) for val in input().split()][0]

    for i in range(t):

        n, a, b, k = [int(val) for val in input().split()]
        
        if(solution(n, a, b, k)):
            print("Win")
        else:
            print("Lose")






