import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()

if __name__ == "__main__":

    # single variables
    n, k, s = [int(val) for val in sys.stdin.readline().split()]


    if(k > s or (n-1)*k < s):
        print("NO")

    else:
        print("YES")

        moves = [1 for val in range(k)]
        summ = k
        move = 0
        while(summ != s):
            val = min(n-2, (s - summ))
            summ += val
            moves[move] += val
            move += 1

        p = True
        house = 1
        for move in moves:
            house = house + move if p else house - move
            p = not p
            print(house, end=' ')

        print('')

