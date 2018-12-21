import sys
sys.setrecursionlimit(2000)

if __name__ == "__main__":

    # single variables
    p = [int(val) for val in input().split()][0]
    q = [int(val) for val in input().split()][0]
   

    goods = []
    for i in range(p, q+1):
        
        d = len(str(i))
        s = str(i*i)
        n = len(s)
        l = s[n-d:]
        r = s[0:n-d]
        try:
            l = int(l)
        except:
            l = 0
        try: 
            r = int(r)
        except:
            r = 0
        if(l+r == i):
            goods.append(i)

    if(len(goods) == 0):
        print("INVALID RANGE")
    else:
        for i in goods:
            print("%d " % (i), end='')
        print('')

     


