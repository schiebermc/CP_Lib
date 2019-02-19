
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

    

if __name__ == '__main__':

    print(mod_divide(11, 56, int(1e9 + 7)))


