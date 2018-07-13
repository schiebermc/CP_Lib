


def solution(p):

    if(len(p) < 2):
        print(-1)
        return 
     
    summ = sum(p)
    for ind, val in enumerate(p):
        if(summ - val != val):
            print(1)
            print(ind+1)
            return
    
    print(-1)


if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]

    # vectors
    p = [int(val) for val in input().split()]
    
    # solve it!
    solution(p)

