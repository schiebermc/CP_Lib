

def db_value(n):
    
    num = 0
    for ind, i in enumerate(reversed(str(n))):
        num += int(i)*2**ind
    return num

def solution(a):

    b = [[db_value(i), i] for i in range(15000)]
    b.sort(key=lambda x: x[0])
    for ind, i in enumerate(b[:1500]):
        print(i[1], ':',  ind)

if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]

    solution(0)
    for i in range(n):
        
        a = [int(val) for val in input().split()][0]

