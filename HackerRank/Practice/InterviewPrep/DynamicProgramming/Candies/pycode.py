
def solution(a, n):
    
    count = 0
    counts = [[0, 0] for i in range(n)]
    for i in range(n):
        if(i-1 == -1):
            left = float('inf')
        else:
            left = a[i-1]
        if(left < a[i]):
            count += 1
        elif(left >= a[i]):
            count = 0
        counts[i][0] = count
    
    count = 0
    for i in range(n-1, -1, -1):
        if(i+1 == n):
            right = float('inf')
        else:
            right = a[i+1]
        if(right < a[i]):
            count += 1
        elif(right >= a[i]):
            count = 0
        counts[i][1] = count

    c1 = [0] * n
    for i in range(n):
        c1[i] = max(counts[i]) + 1    

    print(sum(c1))


if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]

    a = [0] * n
    for i in range(n):
        a[i] = [int(val) for val in input().split()][0]
        
    # solve it!
    solution(a, n)

