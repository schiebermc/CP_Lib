import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()

def ispos(s, sp):
    if(s.replace('a', '') == sp):
        return True

def solution2(t):
    pos = False
    
    n = len(t)
    nh = n//2
    
    bump = n%2
    startind = nh+bump-1
    for i in range(startind, n):
        if(t[i] == 'a'):
            startind = i
    sp = t[startind+1:]

    s = ''   
    for i in range(startind+1):
        if(t[i] != 'a'):
            s += t[i]

    diff = 0
    if(len(sp) > len(s)):
        diff = (len(sp) - len(s))//2
        s += sp[:diff]
        sp = sp[diff:]
        
    pos = ispos(s, sp)
    if(pos):
        s = t[:startind+diff+1]
        return s
    else:    
        return ":("

    
def solution1(t):
    pos = False
    
    n = len(t)
    nh = n//2
    
    bump = n%2
    s = t[:nh+bump]
    sp = t[nh+bump:]
    
    while(len(sp)):
        #print(s, sp)
        pos = ispos(s, sp)
        if(pos):
            break
        s += sp[0]
        sp = sp[1:]
   
    if(not pos):
        pos = ispos(s, sp)
         
    if(pos):
        return s
    else:    
        return ":("

#def validate():
#    import string
#    import random
#    for i in range(1000):
#        random.seed(i)
#        t = ''.join(random.choice(string.ascii_lowercase[:2]) for x in range(10))
#        val1 = solution1(t)
#        val2 = solution2(t)
#        
#        print(i, t, val1, val2)
#        assert val1 == val2

if __name__ == "__main__":
#    validate()
    t = input()
    
    #print(solution1(t))
    print(solution2(t))











