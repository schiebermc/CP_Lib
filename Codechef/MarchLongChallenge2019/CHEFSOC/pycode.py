import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()
from copy import deepcopy

def solution1(a, n, i=0, visited=None, count=0):

    count += 1
    
    if(visited==None):
        visited = set()

    visited.add(i)
    
    if(len(visited) == n):
        return count

    s = a[i]
    for neighbor in range(max(0, i-s), min(n, i+s+1)):
        if(not neighbor in visited):
            new_visited = deepcopy(visited)
            count += solution1(a, n, neighbor, new_visited)

    return count
    

def solution2(a, n, dp, i=0, visited=None, count=0):

    v = [len([val for val in range(max(0, i-s), min(n, i+s+1))]) - 1 for i, s in enumerate(a)]
   
    print(v)
    m = [v[0]]
    for ind, val in enumerate(v[1:]):
        c = int(v[ind-1] == 1)
        if(v[ind] == 2 and ind != 1):
            c += int(v[ind-2] == 1)
        m.append(max(1, v[ind] - c))
    print(m)

if __name__ == "__main__":

    mod_val = int(1e9+7)
    t = [int(val) for val in sys.stdin.readline().split()][0]

    for test in range(t):

        n = [int(val) for val in sys.stdin.readline().split()][0]
        a = [int(val) for val in sys.stdin.readline().split()]

        dp = {}        
        print(solution1(a, n))
        print(solution2(a, n, dp))


