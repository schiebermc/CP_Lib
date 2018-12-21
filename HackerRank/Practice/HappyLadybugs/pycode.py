import sys
sys.setrecursionlimit(2000)
from collections import Counter
# sys.stdin.readline()

def check_board(a, n):
    for i in range(n):
        left = True if i == 0 else a[i] == '_' or a[i-1] == a[i]
        right = True if i == n-1 else a[i] == '_' or a[i+1] == a[i]
        if(not left and not right):
            return False
    return True
        
if __name__ == "__main__":

    # single variables
    g = [int(val) for val in input().split()][0]


    for game in range(g):


        n = [int(val) for val in input().split()][0]
        a = [str(val) for val in input()]
        c = Counter(a)
        pos = True
        if(c['_'] == 0):
            pos = check_board(a, n)
        for key, val in c.items():
            if(key == '_'):
                continue
            if(val == 1):
                pos = False
                break


        if(pos):
            print("YES")
        else:
            print("NO")


