# use this as the main template for python problems
from collections import Counter
import math

def primeFactors(n): 
      
    # Print the number of two's that divide n 
    while n % 2 == 0: 
        yield 2
        n = n / 2
          
    # n must be odd at this point 
    # so a skip of 2 ( i = i + 2) can be used 
    for i in range(3,int(math.sqrt(n))+1,2): 
          
        # while i divides n , print i ad divide n 
        while n % i== 0: 
            yield i
            n = n / i 
              
    # Condition if n is a prime 
    # number greater than 2 
    if n > 2: 
        yield n

def get_prime_factorization(n):
    if(n == 1):
        return {1 : 1}
    primes = {}
    for prime in primeFactors(n):
        prime = int(prime)
        if(prime in primes):
            primes[prime] += 1
        else:
            primes[prime] = 1
    return primes

def next_power_of_2(n):
    return int(math.pow(2, math.ceil(math.log(n)/math.log(2))))

def solution(n):

    pf = get_prime_factorization(n)
    
    lp = 0  
    for key, val in pf.items():
        lp = max(lp, val)
   
    # lp is the largest power in the prime factorization
    # we need the nearest power of two
    np2 = next_power_of_2(lp)
    ans = 1
    for key, val in pf.items():
        ans *= key
    
    moves = 0
    for key, val in pf.items():
        if(val != np2):
            moves = 1
            break
    moves += int(math.log2(np2))

    print(ans, moves)



if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]

    # solve it!
    solution(n)

