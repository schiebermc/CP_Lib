# use this as the main template for python problems
from collections import Counter
from math import ceil

def solution(a):

    row = 5 
    col = 20
    tots = len(a)
    c = Counter(a)
    ac = c['*']

    jump = ceil(tots / ceil(tots / col))
    last = 0
    rows = []
    for x in range(ceil(tots / col)):
        rows.append(a[last:min(tots, last + jump)])
        last += jump
   
    
    to_add = 0
    counts = [0 for i in range(len(rows))]
   
    satisfied = get_satisfied(rows, counts)
    while(not satisfied):
        pos_to_add_to = set([i for i in range(len(rows))])
        
        # remove if it has max as
        max_as = max(counts)
        c1 = Counter(counts)
        for ind, val in enumerate(counts):
            if(val == max_as and len(c1) != 1):
                pos_to_add_to.remove(ind)

        # remove it is is not the minimum length
        min_length = min([len(val) for val in rows])
        for ind, val in enumerate(rows):
            if(len(val) != min_length and ind in pos_to_add_to):
                pos_to_add_to.remove(ind)
        
        # second check to see if there are any more we could add
        if(len(pos_to_add_to) == 0):
            max_length = max([len(val) for val in rows])
            for ind, val in enumerate(rows):
                if(len(val) != max_length):
                    pos_to_add_to.add(ind)
   
        for i in pos_to_add_to:
            rows[i] = rows[i] + '*' 
        
        satisfied = get_satisfied(rows, counts)

    print(len(rows), len(rows[0]))
    for i in rows:
        print(i)


def get_satisfied(rows, counts):
    
    for ind, val in enumerate(rows):
        counts[ind] = Counter(val)['*']
        
    max_as = max(counts)
    for i in counts:
        if(abs(i - max_as) > 1):
            return False

    max_length = max([len(val) for val in rows])
    if(max_length > 20):
        raise Exception

    for val in rows:
        if(len(val) != max_length):
            return False

    return True


if __name__ == "__main__":

    # vectors
    arr = input().split()[0]

    # solve it!
    solution(arr)

