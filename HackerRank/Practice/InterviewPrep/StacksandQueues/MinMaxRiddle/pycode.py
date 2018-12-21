import sys
sys.setrecursionlimit(2000)
from collections import Counter

if __name__ == "__main__":

    n = [int(val) for val in input().split()][0]
    a = [int(val) for val in input().split()]
    sorted_a = [(ind, val) for ind, val in enumerate(a)]
    sorted_a.sort(key=lambda x: x[1])

    size = 1
    answers = []
    for ind, val in reversed(sorted_a):   
        
        if(size > n):
            break
       
        left_bound = ind
        right_bound = ind
        
        while(left_bound != 0 and val < a[left_bound-1]):
            left_bound -= 1
        
        while(right_bound != n-1 and val < a[right_bound+1]):
            right_bound += 1
         
        largest = right_bound - left_bound + 1
        while(largest >= size):
            answers.append(val)
            size += 1
    
    while(len(answers) != n):
        answers.append(val) 

    for i in answers:
        print(i, end=' ')
    print('')

