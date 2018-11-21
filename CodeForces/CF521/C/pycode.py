# use this as the main template for python problems
from collections import Counter

def solution(n, a):
  
    tots = sum(a)
    checks = {}
    for ind, val in enumerate(a):
        if(val in checks):
            checks[val].append(ind+1)
        else:
            checks[val] = [ind+1]


    nice = set([])
    for i in range(n):
        val_needed = tots - 2*a[i]
        if(val_needed in checks):
            if(val_needed != a[i]):
                for i in checks[val_needed]:
                    nice.add(i)
            else:
                adds = set(checks[val_needed])
                adds.remove(i+1)
                for i in adds:
                    nice.add(i)

    print(len(nice))
    for i in nice:
        print("%d " % i, end='')
    print('')
    return len(nice)


def solution2(n, a):
    
    nice = []
    tots = sum(a)
    for i in range(n):
        for j in range(n):
            if(i == j):
                continue
            if(tots - a[i] - a[j] == a[j]):
                nice.append(i+1)
            print(tots - a[i] - a[j], a[j])
    print(nice)
    return len(nice)
    

def validate():
    from random import seed
    from random import randint
    for n in range(2, 10000):
        for j in range(100):
            seed(j)
            a = [randint(1, j+1) for i in range(n)]
            val1 = solution(n, a)
            val2 = solution2(n, a)
            if(val1 != val2):
                print(a)
                print(val1, val2)
                print(n, j)
                raise Exception()

if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]

    # vectors
    arr = [int(val) for val in input().split()]

    #validate()
    # solve it!
    solution(n, arr)

