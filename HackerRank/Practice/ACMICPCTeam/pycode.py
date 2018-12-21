import sys
sys.setrecursionlimit(2000)

if __name__ == "__main__":

    # single variables
    n, m = [int(val) for val in input().split()]
    S = []    
    for i in range(n):
        S.append(set([ind for ind, val in enumerate(input()) if val == '1']))

    best = [0, None]
    for ind1, val1 in enumerate(S):
        for ind2, val2 in enumerate(S[ind1+1:]):
            u = val1.union(val2)
            if(len(u) > best[0]):
                best = [len(u), 1]
            elif(len(u) == best[0]):
                best = [len(u), best[1] + 1]


    print(best[0])
    print(best[1])
