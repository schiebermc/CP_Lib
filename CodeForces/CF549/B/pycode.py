import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()
#from random import seed
#from random import randint
#
#def validate():
#    for i in range(100):
#        seed(i)
#        n = randint(1, 10000)
#        val1 = brute_force(n)
#        val2 = solution(n)
#        print(i, n, val1, val2) 
#        assert val1 == val2
#
#def brute_force(n):
#    val = [str(i) for i in str(n)]
#    if(len(val) < 2):
#        return n
#    best = 0
#    num = None
#    for i in range(10, n+1):
#        v = reduce(lambda x, y : int(x)*int(y), str(i))
#        if(v > best):
#            best = v
#            num = i
#    print(num)
#    
#    return best

def solution(n):
    val = [str(i) for i in str(n)]
    if(len(val) < 2):
        return n

    else:

        best = reduce(lambda x, y : int(x)*int(y), val)
        for i in range(len(val)-2, 0, -1):
            val[i+1] = '9'
            if(val[i] == '0'):
                continue
            
            val[i] = str(int(val[i]) - 1)
            best = max(best, reduce(lambda x, y : int(x)*int(y), val))

        if(val[0] == '1'):
            val = ['9' for i in range(len(val)-1)]
        else:
            val = [str(int(val[0]) - 1)] + ['9' for i in range(len(val)-1)]
        if(len(val) == 1):
            best = max(best, int(val[0]))
        else:
            best = max(best, reduce(lambda x, y : int(x)*int(y), val))
    
    return best

if __name__ == "__main__":

    #validate()
    n = [int(val) for val in sys.stdin.readline().split()][0]
    print(solution(n))


