# use this as the main template for python problems

def count_occurences(s, t, n, N):
    count = 0
    for i in range(0, N-n+1):
        if(s[i:i+n] == t):
            count += 1
    
    return count

def solution(t, n, k):

    # determine overlap of t with itself
    for size in range(1, n+1):
        ov = t[0:size]
        good = True
        for subs in range(n//size+1):
            s2 = t[subs*size:(subs+1)*size]
            #print(ov, t[subs*size:(subs+1)*size])
            if(len(s2) == size):
                if(ov != s2):
                    good = False
                    break
            else:
                for i in range(len(s2)):
                    if(s2[i] != ov[i]):
                        good = False
                        break
        if(good):
            break        

    #print(ov)
    s = ''
    ind = 0
    m = len(ov)
    while(count_occurences(s, t, n, len(s)) != k):
        s += ov[ind%m]
        ind += 1
    print(s)

if __name__ == "__main__":

    # single variables
    n, m = [int(val) for val in input().split()]

    # vectors
    s = [str(val) for val in input().split()][0]

    # solve it!
    solution(s, n, m)



