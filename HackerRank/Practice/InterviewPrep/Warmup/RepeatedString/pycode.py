# use this as the main template for python problems
from collections import Counter

def solution(n, a):

    reps = n // len(a)
    c = Counter(a)
    count = 0
    if('a' in c):
        count += reps * c['a']
    
    diff = n - reps * len(a) 
    for i in range(diff):
        if(a[i] == 'a'):
            count += 1
    print(count)

if __name__ == "__main__":

    # single variables
    a = [str(val) for val in input().split()][0]

    # vectors
    n = [int(val) for val in input().split()][0]

    # solve it!
    solution(n, a)



