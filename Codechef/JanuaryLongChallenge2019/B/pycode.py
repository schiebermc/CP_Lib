import sys
sys.setrecursionlimit(2000)
from collections import Counter
# sys.stdin.readline()

if __name__ == "__main__":

    # single variables
    q = [int(val) for val in input().split()][0]

    for test in range(q):

        n, a, b = [int(val) for val in input().split()]
        arr = [int(val) for val in input().split()]
        
        divs = [0, 0, 0]
        for val in arr:
            if(val % a == 0 and val % b == 0):
                divs[0] += 1
            elif(val % a == 0):
                divs[1] += 1
            elif(val % b == 0):
                divs[2] += 1

        if(divs[0] != 0):
            divs[1] += 1

        if(divs[2] >= divs[1]):
            print("ALICE")
        else:
            print("BOB")
        


