


if __name__ == "__main__":

    n, k = [int(val) for val in input().split()]
    s = input().split()[0]
   
    if(n == k):
        print(s)
    
    else :

        s2 = ''
        size = 0
        count = 0
        for x in s:
            
            if(size == k):
                break

            if(x == '('):
                if(count >= k - size):
                    pass
                else:
                    s2 += x
                    size += 1
                    count += 1
            
            elif(count > 0):
                s2 += x
                size += 1
                count -= 1
     
        print(s2) 
 
