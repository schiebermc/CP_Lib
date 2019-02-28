import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()

def swap(s, ind):
    ind -= 1
    s = s[:ind] + s[ind+1] + s[ind] + s[ind+2:]
    return s

if __name__ == "__main__":

    # single variables
    n = [int(val) for val in sys.stdin.readline().split()][0] 
    s = [str(val) for val in sys.stdin.readline().split()][0]
    t = [str(val) for val in sys.stdin.readline().split()][0]

    if(Counter(s) != Counter(t)):
        print(-1)

    else:

        moves = []
        for i in range(len(s)-1):
            c = t[i]    
            ind = i
            while(s[ind] != c):
                ind += 1
           
            for j in range(ind-1, i-1, -1):
                s = swap(s, j+1)
                moves.append(j+1)
    
        print(len(moves))
        for move in moves:
            print(move, end=' ')
        print('')
    
