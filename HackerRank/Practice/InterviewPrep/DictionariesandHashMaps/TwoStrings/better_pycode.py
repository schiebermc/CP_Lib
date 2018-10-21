# use this as the main template for python problems
from collections import Counter



def solution(s1, s2):

    S1 = set(s1)
    S2 = set(s2)
    intersection_set = S1.intersection(S2)

    pos = len(intersection_set)    
    
    if(pos):
        print("YES")
    else:
        print("NO")


if __name__ == "__main__":

    # single variables
    m = [int(val) for val in input().split()][0]
    
    for i in range(m):
        
        # solve it!
        s1 = [str(val) for val in input().split()][0]
        s2 = [str(val) for val in input().split()][0]
        solution(s1, s2)

