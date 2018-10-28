# use this as the main template for python problems
from collections import Counter

def solution(a):
    
    counts = [val for key, val in Counter(a).items()]
    freqs = Counter(counts)
    
    largest = [0, 0]
    for key, val in freqs.items():
        if(val > largest[1]):
            largest = [key, val]

    pos = True
    changed = False
    for count in counts:
        if(count == largest[0]):
            pass
        else:
            if(changed or abs(count-largest[0]) > 1 and not (count == 1 or (largest[0] == 1 and freqs[largest[0]] == 1))):
                pos = False
                break
            else:
                changed = True

    if(pos):
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":

    # single variables
    n = [str(val) for val in input().split()][0]
    solution(n)

