import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()
import time

from itertools import combinations

def solution1(N, D):
    count = 0
    for combo in combinations(D, 2):
        if(len(set(combo[0]).union(set(combo[1]))) == 5):
            count += 1
    return count


def solution2(N, D):
    vowels = ['a', 'e', 'i', 'o', 'u']
    svowels = set(vowels)
    
    #D = set(D)
    #D = set()
    #for dish in range(N):
    #    D.add(input())
    D = [sorted(set(dish)) for dish in D]
    
    G = {() : N-1}
    for size in range(5):
        for combo in combinations(vowels, size+1):
            G[combo] = 0 

    for dish in D:
        for size in range(len(dish)):
            for combo in combinations(dish, size+1):
                G[combo] += 1

    count = 0
    for dish in D:
        diff = svowels.difference(set(dish))
        count += G[tuple(sorted(diff))]
    return count//2                    


def validate():
    from random import seed
    from random import choice
    from random import randint

    seed(1)
    t = 10
    N = 5000
    n = 1000

    T = 0.0
    vowels = ['a', 'e', 'i', 'o', 'u']
    for test in range(t):

        D = []
        for dish in range(N):
            d = ''
            for count in range(randint(1, n)):
                d += choice(vowels)
            D.append(d) 

        t0 = time.time()       
        solution2(N, D)
        T += time.time() - t0
        
    print(T)


if __name__ == "__main__":

    #validate()

    t = [int(val) for val in sys.stdin.readline().split()][0]

    for test in range(t):
    
        N = [int(val) for val in sys.stdin.readline().split()][0]

        D = [sys.stdin.readline()[:-1] for dish in range(N)]
        
        print(solution2(N, D))
        



 
