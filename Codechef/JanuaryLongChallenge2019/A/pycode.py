import sys
sys.setrecursionlimit(2000)
from collections import Counter
# sys.stdin.readline()

if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]

    for i in range(n):
        s = ' ' + input() + ' ' 

        if(' not ' in s):
            print("Real Fancy")
        else:
            print("regularly fancy")
    


