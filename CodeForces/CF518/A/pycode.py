# use this as the main template for python problems
from collections import Counter
from math import ceil
def solution(arr):

    n, m, k, l = arr
    diff = n-k

    # ALLL MUST GIVE THEE SAME AMOUNT
    # ALL COINS GIVEN TO IVAN MUSST BE DIFFERENT
    # L Must be new
    # WE DON"T KNOW WHICH ONES HE HAS

    if(diff < l or n < m):
        print("-1")
    else:
        c = ceil((l+k)/float(m))
        print(c)

if __name__ == "__main__":

    # vectors
    arr = [int(val) for val in input().split()]

    # solve it!
    solution(arr)



