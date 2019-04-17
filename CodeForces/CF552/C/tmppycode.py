import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()
from copy import deepcopy

def solution2(vec):
    
    eats = [3, 2, 2]
    weeks = [vec[ind] // val for ind, val in enumerate(eats)]
    min_weeks = min(weeks)
    vec = [val - eats[ind]*min_weeks for ind, val in enumerate(vec)]

    min_days = min_weeks*7
    best = min_days
    eats = [0, 0, 1, 2, 0, 2, 1] 
    
    for start in range(7):
        food = deepcopy(vec)
        days = min_days
        while(True):
            day = (start + days)%7
            eat = eats[day]
            if(food[eat] == 0):
                break
            food[eat] -= 1
            days += 1

        best = max(best, days)
    return best
    
if __name__ == "__main__":

    # single variables
    vec = [int(val) for val in sys.stdin.readline().split()]
    print(solution2(vec))
    #validate()        


