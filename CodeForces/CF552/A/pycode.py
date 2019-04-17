import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()

if __name__ == "__main__":

    # single variables
    vec = [int(val) for val in sys.stdin.readline().split()]
    abc = max(vec)
    vec.remove(abc)
    for val in vec:
        print(abc-val, end=" ")
    print("")

