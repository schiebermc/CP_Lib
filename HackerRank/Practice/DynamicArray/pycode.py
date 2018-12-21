import sys
sys.setrecursionlimit(2000)
from collections import Counter
# sys.stdin.readline()


if __name__ == "__main__":

    # single ariables
    n, q = [int(val) for val in input().split()]

    seqList = []
    for i in range(n):
        seqList.append([])

    lastAnswer = 0
    for Q in range(q):
    
        t, x, y = [int(val) for val in input().split()]
        ind = (x ^ lastAnswer) % n
        
        if(t == 1):
        
            seqList[ind].append(y)

        else:
    
            ind2 = y % len(seqList[ind])
            lastAnswer = seqList[ind][ind2]
            print(lastAnswer)
        
    


