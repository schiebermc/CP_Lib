# use this as the main template for python problems
from collections import Counter

def solution(arr):

    pos = True
    stack = []
    for i in arr:
        if(i == ')'):
            if(len(stack) and stack[-1] == '('):
                stack.pop()
            else:
                pos = False
                break
        

        elif(i == ']'):
            if(len(stack) and stack[-1] == '['):
                stack.pop()
            else:
                pos = False
                break
    
        elif(i == '}'):
            if(len(stack) and stack[-1] == '{'):
                stack.pop()
            else:
                pos = False
                break

        else:
            stack.append(i)


    if(pos and len(stack) == 0):
        print("YES")
    else:
        print("NO")



if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]

    for i in range(n):
        
        # vectors
        arr = input().split()[0]
        
        # solve it!
        solution(arr)

