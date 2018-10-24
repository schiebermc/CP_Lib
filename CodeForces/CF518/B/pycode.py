# use this as the main template for python problems
from collections import Counter
import math 
  
# A function to print all prime factors of  
# a given number n 
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


def solution(n):

    primes = {}
    for prime in primeFactors(n):
        if(prime in primes):
            primes[prime] += 1
        else:
            primes[prime] = 1
    
    tots = 1
    for key, val in primes.items():
        tots *= (val + 1)
    
    print(tots)

if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]

    # solve it!
    solution(n)

