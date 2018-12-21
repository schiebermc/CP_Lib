import sys
sys.setrecursionlimit(2000)

if __name__ == "__main__":

    # single variables
    s = input().split()[0]
    t = input().split()[0]
    k = [int(val) for val in input().split()][0]

    ind = 0
    while(ind < len(s) and ind < len(t)):
        if(t[ind] != s[ind]):
            break
        ind += 1

    # fastest way to do it:
    # (len(s) - ind) + (len(t) - ind)
    # slowest way to efficiently do it
    # len(s) + len(t)
    # between these two values, you can do it every way with increments of 2

    val1 = (len(s) - ind) + (len(t) - ind)
    val2 = len(s) + len(t)

    diffs = set([])
    for val in range(val1, val2+1, 2):
        diffs.add(val)

    # afte that, every way up to k is possible with increment of one 
    for val in range(val2, k+1):
        diffs.add(val)

    pos = k in diffs
    if(pos):
        print("Yes")
    else:
        print("No")



