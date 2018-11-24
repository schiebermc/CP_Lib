import sys
sys.setrecursionlimit(2000)
from collections import Counter
from collections import OrderedDict
from math import ceil

def solution(n, g, a):
    solution2(n, g, a)

def solution2(n, g, a):
    a.sort()
    rates = [1./val for val in a]
    lower_bound = 1
    upper_bound = ceil(g / rates[0])

    # we need to find the first day stepping forward from lower bound
    # that works.  
    from time import sleep
    satisfied = False
    while(not satisfied):

        days = (upper_bound + lower_bound) // 2
        works1 = works(n, g, a, days-1)
        works2 = works(n, g, a, days)
        
        #sleep(1)
        #print(days)

        if(works2 and not works1):
            satisfied = True

        else:
            
            if(works1 and works2): # search down
                
                upper_bound = days - 1

            elif(not works1 and not works2):
            
                lower_bound = days + 1

            else:
                raise Exception()

    print(days)
       
 

def works(n, g, a, days):
    toys = 0
    for i in a:
        toys += days // i
    if(toys >= g):
        return True
    else:
        return False
    

def solution1(n, g, a):

    rates = [1./val for val in a]
    total_rate = sum(rates)
    days = ceil(round(g/total_rate, 4))
    toys = 0
    for i in a:
        toys += days // i
    
    while(toys < g):
        days += 1
        for i in a:
            if(days % i == 0):
                toys += 1
    print(days)


if __name__ == "__main__":

    # single variables
    n, g = [int(val) for val in input().split()]

    # vectors
    a = [int(val) for val in input().split()]

    # solve it!
    solution(n, g, a)



