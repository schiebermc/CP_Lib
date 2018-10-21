# use this as the main template for python problems
from collections import Counter


def match(d1, d2):
    for sub in d1:
        if(sub in d2):
            return True
    return False

def substring_dict(s, n):
    d = set([])
    for i in range(len(s)-n+1):
        sub = s[i:i+n]
        d.add(sub)
    return d

def do_these_words_match(s1, s2):

    pos = False
    for n in range(1, min(len(s1), len(s2))+1):
        d1 = substring_dict(s1, n)
        d2 = substring_dict(s2, n)

        if(match(d1, d2)):
            pos = True
            break

    return pos

def solution(s1, s2):

    S1 = set(s1)
    S2 = set(s2)
    diff_set = S1.difference(S2)
    
    s1 = prune_on_diff(diff_set, s1)
    s2 = prune_on_diff(diff_set, s2)

    pos = False
    for substring1 in s1:
        for substring2 in s2:
            if(do_these_words_match(substring1, substring2)):
                pos = True
                break
    if(pos):
        print("YES")
    else:
        print("NO")


def prune_on_diff(diff_set, s):
    substrings = []
    ind = 0
    while(ind < len(s)):
        if(s[ind] in diff_set):
            s1 = s[:ind]
            s = s[ind+1:]
            if(s1):
                substrings.append(s1)
            ind = 0
        else:
            ind += 1
    substrings.append(s)
    return substrings


if __name__ == "__main__":

    # single variables
    m = [int(val) for val in input().split()][0]
    
    for i in range(m):
        
        # solve it!
        s1 = [str(val) for val in input().split()][0]
        s2 = [str(val) for val in input().split()][0]
        solution(s1, s2)

