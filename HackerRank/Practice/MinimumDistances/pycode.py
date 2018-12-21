import sys
sys.setrecursionlimit(2000)

if __name__ == "__main__":

    n = [int(val) for val in input().split()]
    a = [int(val) for val in input().split()]
       
    best = float('inf')
    for ind1, val1 in enumerate(a): 
        for ind2, val2 in enumerate(a[ind1+1:]): 
            if(val1 == val2):
                best = min(best, ind2+1)

    if(best == float('inf')):
        print(-1)
    else:
        print(best)
