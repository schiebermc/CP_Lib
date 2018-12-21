import math
from functools import reduce

def get_number_of_divisors(n):
    if(n == 1):
        return 1
    primes = get_prime_factorization(n)
    return reduce(lambda x, y : x*y, [val+1 for key, val in primes.items()])

def primeFactors(n): 
    while n % 2 == 0: 
        yield 2
        n = n / 2
    for i in range(3,int(math.sqrt(n))+1,2): 
        while n % i== 0: 
            yield i
            n = n / i 
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

def triangular_numbers(n):
    numbers = []
    count = 0
    ind = 1
    while(count < n):
        number = ((ind + 1) * ind) // 2     
        ndivisors = get_number_of_divisors(number)
        while(ndivisors > count and count < n):
            numbers.append(number)
            count += 1
        ind += 1
    return numbers

def longest_collats

if __name__ == "__main__":
    
    numbers = triangular_numbers(1000)
    print(numbers)

