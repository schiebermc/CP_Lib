# use this as the main template for python problems
from collections import Counter

def solution(a, b, knights):

    pos = False
    for new_a, new_b in pos_moves(a, b):
        pos = not can_be_attacked(new_a, new_b, knights)
        if(pos):
            break
    
    if(pos):
        print("NO")
    else:
        print("YES")

def can_be_attacked(a, b, knights):
    for ak, bk in knights:
        if(abs(a - ak) == 1 and abs(b - bk) == 2):
            return True
        if(abs(a - ak) == 2 and abs(b - bk) == 1):
            return True
    return False


def pos_moves(a, b):
    for i in [-1, 0, 1]:
        for j in [-1, 0, 1]:
            yield a+i, b+j


if __name__ == "__main__":

    # single variables
    T = [int(val) for val in input().split()][0]

    for i in range(T):
    
        N = [int(val) for val in input().split()][0]
        
        knights = []
        for knight in range(N):
            knights.append([int(val) for val in input().split()])

        
        a, b = [int(val) for val in input().split()]
        # solve it!
        solution(a, b, knights)

