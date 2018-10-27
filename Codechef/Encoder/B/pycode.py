# use this as the main template for python problems
from collections import Counter

def  solution(n, m, h, c):
    
    colored = []
    for ind, i in enumerate(h):
        while(len(colored) != 0 and i >= colored[0][0]):
            colored.pop(0)
        colored.insert(0, (i, c[ind]))

    colors = set([])
    for i in colored:
        colors.add(i[1])

    print(len(colors))

if __name__ == "__main__":

    # single variables
    T = [int(val) for val in input().split()][0]

    for i in range(T):
    
        n, m = [int(val) for val in input().split()]
        h = [int(val) for val in input().split()]
        c = [int(val) for val in input().split()]
        
        solution(n, m, h, c)
