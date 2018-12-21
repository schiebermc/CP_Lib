import sys
# sys.stdin.readline()
def solution(n, a):
    days = 0
    while(days < 100):
        good = True 
        new_a = [a[0]]
        for ind, val  in enumerate(a[1:]):
            if(val <= a[ind]):
                new_a.append(val)
            else:
                good = False
        a = new_a
        days += 1
        if(good):
            break
    if(days == 100):
        return -1
    #print(days-1)    
    return days -1 


def solution2(n, a):

    minn = min(a)
    inds = [0]
    for ind, val in enumerate(a[1:]):
        if(val == minn):
            inds.append(ind+1)
    inds.append(n)
    
    segments = []
    for ind, val in enumerate(inds[:-1]):
        segments.append(a[val:inds[ind+1]])

    # optimization: sort segments, can skip to sol if best > len(segment)
    segments.sort(key=len, reverse=True)
    best = 0    
    #print(len(segments[0]), min(segments[0]), len(segments[1]), min(segments[1]))
    for segment in segments:
        best = max(best, get_max_on_segment(segment, best))
    #print(best)
    return best


def get_max_on_segment(segment, running_best):

    if(len(segment) <= 1 or running_best >= len(segment)):
        return 0

    minn = min(segment)
    stacks  = [] # non increasing sequence
    largest_preceding = minn
    for i in segment[1:]:
        if(len(stacks) == 0):
            stacks.append([i])
            largest_preceeding = i
        else:
            added = False
            dels = []
            for ind, stack in enumerate(stacks):
                if(i <= stack[-1]):
                    dels.append(ind)
                    stack.append(i)
                    added = True    
            
            if(not added):
                stacks.append([i])
                largest_preceding = i
            else:
                best = [0, None]
                for ind in dels:
                    val = len(stacks[ind])
                    best = [val, ind] if best [0] < val else best
                count = 0
                for ind in dels:
                    if(ind != best[1]):
                        del stacks[ind - count] 
                        count += 1

    best = 0
    for stack in stacks:
        if(minn == stack[-1]):
            continue
        count = 0
        for val in stack:
            if val == minn:
                count += 1
        best = max(best, len(stack) - count)
    return best


def validation():
    n = int(15)
    from random import randint
    from random import seed
    for s in range(10):
        seed(s)
        #a = [randint(0, int(1e9)) for i in range(n)]
        a = [randint(0, int(15)) for i in range(n)]
        #print(a)
        val1 = solution(n, a)
        val2 = solution2(n, a)
        if(val1 != val2):
            raise Exception("failed at seed %d" % s)


if __name__ == "__main__":

    n = [int(val) for val in input().split()][0]
    a = [int(val) for val in sys.stdin.readline().split()]

    #validation()
    val = solution(n, a)
    if(val == -1):
        val = solution2(n, a)

    print(val)


