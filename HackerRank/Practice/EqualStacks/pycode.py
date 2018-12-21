import sys
sys.setrecursionlimit(2000)

if __name__ == "__main__":

    # single variables
    n1, n2, n3 = [int(val) for val in input().split()]
    s1 = [int(val) for val in reversed(input().split())]
    s2 = [int(val) for val in reversed(input().split())]
    s3 = [int(val) for val in reversed(input().split())]

    S = [s1, s2, s3]
    H = [sum(stuff) for stuff in S]

    count = 0
    pos = False
    while(len(S[0]) != 0 and len(S[1]) != 0 and len(S[2]) != 0):
        
        if(H[0] == H[1] and H[1] == H[2]):
            pos = True
            break

        info = [(0, H[0], S[0][-1]), (1, H[1], S[1][-1]), (2, H[2], S[2][-1])]
        
        info.sort(key=lambda x : x[2])
        info.sort(key=lambda x : x[1], reverse = True)
        ind = info[0][0]
        H[ind] -= S[ind][-1]
        S[ind].pop()

        count += 1

    if(pos):
        print(H[0])
    else:
        print(0)
            


