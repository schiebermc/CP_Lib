import sys
sys.setrecursionlimit(2000)
from collections import Counter
# sys.stdin.readline()

def query(x, y):
    print("Q %d %d" % (x, y))   
    sys.stdout.flush()
    return [int(val) for val in input().split()][0]

if __name__ == "__main__":

    t = [int(val) for val in input().split()][0]
    
    c = int(1e9)

    for test in range(t):
    
        q1 = query(0, 0)
        q2 = query(c, c)
        q3 = query(0, c)
        q4 = query(c, 0)

        d1 = q1
        d2 = 2*c - q2
        d3 = q3 - c
        d4 = q4 - c
    
        val = (d1 + d2 + d3 - d4)//4
        yl = query(val, 0)

        xl = d1 - yl
        xu = yl - d4
        yu = xl - d3

        s = "A %d %d %d %d" % (xl, yl, xu, yu)
        print(s)
        sys.stdout.flush()
       
        ans = [int(val) for val in input().split()][0]
        assert ans == 1
        

