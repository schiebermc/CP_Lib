# use this as the main template for python problems
from collections import Counter

def solution(magazine, note, m, n):

    dm = strings_to_dict(magazine)
    dn = strings_to_dict(note)

    pos = True
    for i in dn:
        if(not i in dm or dm[i] < dn[i]):
            pos = False
            break
    if(pos):
        print("Yes")
    else:
        print("No")


def strings_to_dict(strings):
    d = {}
    for i in strings:
        if(i in d):
            d[i] += 1
        else:
            d[i] = 1
    return d

if __name__ == "__main__":

    # single variables
    m, n = [int(val) for val in input().split()]

    magazine = [str(val) for val in input().split()]
    note = [str(val) for val in input().split()]
    

    # solve it!
    solution(magazine, note, n, m)

