# use this as the main template for python problems
from collections import Counter

def solution(a, b):

    c1 = Counter(a)
    c2 = Counter(b)
    
    print(equalize(c1, c2) + equalize(c2, c1)) 

def equalize(c1, c2):
    count = 0
    for key, val in c1.items():
        if(not key in c2):
            count += val
            c1[key] = 0
        else:
            diff = c1[key] - c2[key]
            if(diff < 0):
                c2[key] += diff
            else:
                c1[key] -= diff
            count += abs(diff)
    return count

if __name__ == "__main__":

    # single variables
    a = [str(val) for val in input().split()][0]
    b = [str(val) for val in input().split()][0]

    # solve it!
    solution(a, b)

