

if __name__ == "__main__":


    # single variables
    t = [int(val) for val in input().split()][0]

    # vectors
    for i in range(t):
        L, v, l, r  = [int(val) for val in input().split()]
        lanterns = L // v
        ld = l // v
        rd = r // v
        st = rd - ld
        if(l % v == 0):
            st += 1
        print(lanterns - st)
        





