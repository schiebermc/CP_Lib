import sys
sys.setrecursionlimit(2000)
from collections import Counter
from functools import reduce
# sys.stdin.readline()

if __name__ == "__main__":

    # single variables
    n = [int(val) for val in sys.stdin.readline().split()][0]
    a = [int(val) for val in sys.stdin.readline().split()]
   
    days = 0    
    mysteries = set([])
    pages = set([val for val in range(n)]) 
    
    for page in range(n):

        if(len(mysteries) == 0):
            days+=1
        
        if(page in mysteries):
            mysteries.remove(page)        

        new_page = a[page]-1
        if(new_page > page):
            mysteries.add(new_page)

    print(days)
             


