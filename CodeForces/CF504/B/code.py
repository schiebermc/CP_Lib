


if __name__ == "__main__":

    n, k = [int(val) for val in input().split()]

    if(n*2 < k):
        print(0)
    
    elif(n>= k):
        if(k%2):
            print(k // 2)
        else:
            print(k // 2 - 1)
    else:
        bot = k - n;
        print((n - bot + 1) // 2)


