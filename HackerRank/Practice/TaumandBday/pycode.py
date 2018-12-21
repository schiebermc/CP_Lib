import sys
sys.setrecursionlimit(2000)

if __name__ == "__main__":

    # single variables
    t = [int(val) for val in input().split()][0]
    for test in range(t):
        b, w = [int(val) for val in input().split()]
        bc, wc, z = [int(val) for val in input().split()]
        
        cost = 0
       
        # buy white gifts
        c = z + bc
        if(c < wc):
            cost += c*w
        else:
            cost += wc*w

        c = z + wc
        if(c < bc):
            cost += c*b
        else:
            cost += bc*b

        print(cost)
    


