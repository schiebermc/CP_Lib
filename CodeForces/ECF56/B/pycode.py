import sys
sys.setrecursionlimit(2000)
from collections import Counter

def is_palindrome(s):
    for i in range(len(s)//2):
        if(s[i] != s[len(s)-1-i]):
            return False
    return True

if __name__ == "__main__":

    # single variables
    t = [int(val) for val in input().split()][0]

    for test in range(t):
        a = [str(val) for val in input()]


        c = Counter(a)
        s = ''
        for key, val in c.items():
            s += key*val
        
        pos = is_palindrome(s)
        if(pos):
            print(-1)
        else:
            print(s)

