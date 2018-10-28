# use this as the main template for python problems
from collections import Counter

def solution(n, s):
        
    count = 0
    s1 = []
    current = s[0]
    for i in s:
        if(i == current):
            count += 1
        else:
            s1.append((current, count))
            count = 1
            current = i     
    s1.append((current, count))

    n1 = len(s1)
    count = 0
    for ind, val in enumerate(s1):
        key, val = val
        

        count += (val+1)*val // 2
        
        if(ind < n1 - 2 and s1[ind+1][1] == 1 and s1[ind+2][0] == key):
            count += min(val, s1[ind+2][1])
        
    print(count)


    
if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]
    s = [str(val) for val in input().split()][0]
    solution(n, s)

