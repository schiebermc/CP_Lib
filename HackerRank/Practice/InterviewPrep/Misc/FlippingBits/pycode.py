import sys
sys.setrecursionlimit(2000)
from collections import Counter

def bitstring_to_int(b):
    n = 0
    for ind, val in enumerate(reversed(b)):
        n += int(val) * 2 ** ind
    return n


def int_to_bitstring(b):
    s = ''
    ind = 0
    while(2**ind <= b):
        ind += 1

    ind -= 1
    for i in range(31, ind, -1):
        s += '0'
    for i in range(ind, -1, -1):
        if(b >= 2**i):
            s += '1'
            b -= 2**i    
        else:
            s += '0'
    
    return s

def flip_bitstring(b):
    b2 = ''
    for i in b:
        b2 += '1' if i == '0' else '0'
    return b2

if __name__ == "__main__":

    # single variables
    q = [int(val) for val in input().split()][0]

    for i in range(q):
        n = [int(val) for val in input().split()][0]

        # convert n to binary
        b = int_to_bitstring(n)   
        b = flip_bitstring(b)
        print(bitstring_to_int(b))

