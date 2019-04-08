import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()

if __name__ == "__main__":

    t = [int(val) for val in sys.stdin.readline().split()][0]

    for test in range(t):

        N = sys.stdin.readline().replace('\n', '')
        
        A = ''
        B = ''
        for char in N:
            if(char == '4'):
                A += '3'
                B += '1'
            else:
                A += char
                B += '0'        

        print("Case #%d: %d %d" % (test+1, int(A), int(B)))

