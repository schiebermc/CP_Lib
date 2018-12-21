import sys

if __name__ == "__main__":

    # single variables
    s = [str(val) for val in input().split()][0]
    

    singles = 0
    for i in s:
        if(i == 'a'):
            singles +=1 

    count = 0
    groups = []
    for i in s:
        if(i == 'a'):
            count += 1
        if(i == 'b' and count != 0):
            groups.append(count)
            count = 0
    
    if(count != 0):        
        groups.append(count)
    
    modval = int(1e9+7)
    tots = 1
    for i in groups:
        tots = ((tots % modval) * ((i+1) % modval)) % modval
    print(tots-1)



