# use this as the main template for python problems

if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]

    full_names = {}
    names = {}
    for x in range(n):
        name = [str(val) for val in input().split()][0]
        if (name in full_names):
            print(name + ' ' + str(full_names[name]+1))
            full_names[name] += 1
            
        else:    
        
            printed = False
            pos = ''
            for i in name:
                pos += i
                if(pos in names):
                    continue
                else:
                    if(not printed):
                        print(pos)
                        printed = True
                    names[pos] = 1
            
            if(not printed):
                print(pos)
                full_names[pos] = 1
            full_names[name] = 1


