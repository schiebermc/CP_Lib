import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()

if __name__ == "__main__":

    # single variables
    n = [int(val) for val in sys.stdin.readline().split()][0]
    s = sys.stdin.readline().replace('\n', '')

    g = "ACTG"
    costs = []
    for ind1, val1 in enumerate(g):
        costs.append([])
        for ind2, val2 in enumerate(s):
            costs[ind1].append(min((ord(val1) - ord(val2)) % 26, (ord(val2) - ord(val1)) % 26))

    best = float("inf")
    for i in range(n-3):
        best = min(best, costs[0][i] + costs[1][i+1] + costs[2][i+2] + costs[3][i+3]) 
    print(best)


