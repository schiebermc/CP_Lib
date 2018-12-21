import sys
sys.setrecursionlimit(2000)
from collections import Counter
# sys.stdin.readline()
import math

if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]
    s = [str(val) for val in input().split()][0]
 
    numbers = "0123456789"
    lower_case = "abcdefghijklmnopqrstuvwxyz"
    upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    special_characters = "!@#$%^&*()-+"


    bumps = [1,1,1,1]
    for i in s:
        if(i in numbers):
            bumps[0] = 0
        if(i in lower_case):
            bumps[1] = 0
        if(i in upper_case):
            bumps[2] = 0
        if(i in special_characters):
            bumps[3] = 0

    print(max(6 - n, sum(bumps)))

