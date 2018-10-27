
def brute_force(a, n):
    best = float('-inf')
    for i in range(n):
        smallest = float('inf')
        for j in range(i, n):
            if(a[j] < smallest):
                smallest = a[j]
            area = smallest * (j - i + 1)
            if(area > best):
                best = area
    return best


def get_index_bounds(val, i, a, n):

    left = i
    right = i
    while(left >= 0 and a[left] >= val):
        left -= 1
    while(right < n and a[right] >= val):
        right += 1
    
    if(left == -1 or a[left] < val):
        left += 1
    if(right == n or a[right] < val):
        right -= 1
    return left, right    


def solution(a, n):
    
    # weird solution incoming
    # do a double for loop as before, with a key assumption:
    # if we encounter

    best = float('-inf')
    for i in range(n):
        val = a[i]
        left, right = get_index_bounds(val, i, a, n)
        area = (right - left + 1) * val
        #print(i, val, left, right, area)
        if(area > best):
            best = area 

    print(best)
    



if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]
    a = [int(val) for val in input().split()]

    solution(a, n)

    



