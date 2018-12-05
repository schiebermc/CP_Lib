import sys
sys.setrecursionlimit(2000)
from collections import Counter

def solution(n):
    pair = None
    good = False
    for a in range(1, 200):
        for b in range(1, 200):

            if(a%b == 0 and a*b > n and a//b < n):
                good = True
                pair = [a, b]
                break
   
        if(good):
            break
 
    if(good):
        print("%d %d" % (pair[0], pair[1]))

    else:
        print("-1")

def solution2(x):
    if(x == 1):
        print("-1")
    else:
        print("%s %s" % (int(x/2)*2, 2))

if __name__ == "__main__":


    # single variables
    n = [int(val) for val in input().split()][0]

    solution(n)


    for i in range(1, 101):
        #print(i)
        solution2(i)
