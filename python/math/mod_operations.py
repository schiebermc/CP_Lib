
def mod_sum(vec, m):
    summ = 0
    for val in vec:
        summ = ((summ % m) + (val % m) ) % m
    return summ

def mod_add(a, b, m):
    return ((a % m) + (b % m)) % m


def mod_power(x, y, p):
    # computes x ^ y % p 
    res = 1
    x = x % p  
    while (y > 0) : 
        if ((y & 1) == 1) : 
            res = (res * x) % p 
        y = y >> 1 
        x = (x * x) % p 
    return res 


