# use this as the main template for python problems
from collections import Counter
import sys
sys.setrecursionlimit(2000)
        
def pos_from_here(aind, bind, a, b, saved):
    
    answer = True
    if((aind, bind) in saved):
        return saved[(aind, bind)]

    elif(bind == len(b)):
        for i in range(aind, len(a)):
            if(ord(a[i]) < 97):
                answer = answer and False

    elif(aind == len(a)):
        answer = False

    elif(ord(a[aind]) < 97):
        if(a[aind] == b[bind]):
            answer = pos_from_here(aind+1, bind+1, a, b, saved)
        else:
            answer = False        
    else:
        # soooo... it's this then that, it's either or
        pos1 = False
        if(chr(ord(a[aind]) - 32) == b[bind]):
            pos1 =  pos_from_here(aind+1, bind+1, a, b, saved)
            
        pos2 = pos_from_here(aind+1, bind, a, b, saved)
        answer =  pos1 or pos2

    saved[(aind, bind)] = answer
    return answer

def solution(a, b):
    
    saved = {}
    pos = pos_from_here(0, 0,  a, b, saved)
    
    if(pos):
        print("YES")
    else:
        print("NO")
        
if __name__ == "__main__":

    # single variables
    q = [int(val) for val in input().split()][0]

    diff = 32
    for i in range(q):

        a = [str(val) for val in input().split()][0]
        b = [str(val) for val in input().split()][0]

        solution(a, b)    

       
        
 

