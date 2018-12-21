import sys
sys.setrecursionlimit(2000)

if __name__ == "__main__":

    t = [int(val) for val in input().split()][0]
    for test in range(t):

        n, c, m = [int(val) for val in input().split()]
    
        buys = n // c
        c = n % c
        
        w = buys
        while(w >= m):
            w -= m
            buys += 1
            w += 1
        print(buys)



