import sys
sys.setrecursionlimit(2000)

if __name__ == "__main__":

    # single variables
    p, d, m, s = [int(val) for val in input().split()]

    val = p
    count = 0
    while(s >= val):

        s -= val
        val = val - d if val - d >= m else m
        count += 1

    print(count)

