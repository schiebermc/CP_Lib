
def ways(info, k, stocks):    
    includes = {}
    for i, j in info:
        if(not j in includes or not i in includes or (not i in includes[j] and not j in includes[i])):            
            # add to j's includes set
            if(i in includes):
                if(j in includes):
                    includes[i] = includes[j].union(includes[i])
                else:
                    includes[j] = includes[i]
            else:
                if(j in includes):
                    pass
                else:
                    includes[j] = set([])
            includes[j].add(i)
               
            # add to i's includes set
            if(j in includes):
                if(i in includes):
                    includes[i] = includes[i].union(includes[j])
                else:
                    includes[i] = includes[j]
            else:
                if(i in includes):
                    pass
                else:
                    includes[i] = set([])
            includes[i].add(j)
    
    s = 0
    included = set([])
    for x in stocks:
        if(not x in included):
            s += 1
            if(x in includes):
                included = included.union(includes[x])
    #print(included)
    #print(includes)
    #print(s)
    #print(stocks)
    return (2 ** s) % int(1e9 + 7)

def get_info(p, infos):  
    info = []
    while(p in infos):
        info += [infos[p][1]]
        p = infos[p][0]
    return info
    
if __name__ == "__main__":

    n, q = [int(val) for val in input().split()]
    infos = {}

    for query in range(1, q+1):

        I = [int(val) for val in input().split()]
        if(I[0] == 1):
            p, i, j = I[1:]
            infos[query] = ([p, [i, j]])   
        
        else:
            
            p = I[1]
            k = I[2]
            stocks = I[3:]
            print(ways(get_info(p, infos), k, stocks))
 




