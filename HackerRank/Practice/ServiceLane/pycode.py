import sys
sys.setrecursionlimit(2000)

if __name__ == "__main__":

    n, t = [int(val) for val in input().split()]

    a = [int(val) for val in input().split()]
    for test in range(t):
        ind1, ind2 = [int(val) for val in input().split()]
        print(min(a[ind1:ind2+1]))
        

