import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()

if __name__ == "__main__":
    n = [int(val) for val in sys.stdin.readline().split()][0]
    summ = 0
    for i in range(n-2):
        summ += 1*(i+2)*(i+3)
    print(summ)



