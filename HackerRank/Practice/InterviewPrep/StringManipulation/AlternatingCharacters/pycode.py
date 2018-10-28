# use this as the main template for python problems
from collections import Counter

def solution(a):

    count = 0
    last = None
    for i in a:
        if(last == i):
            count += 1
        last = i
    print(count)

if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]
    
    for i in range(n):
        b = [str(val) for val in input().split()][0]

        # solve it!
        solution(b)

