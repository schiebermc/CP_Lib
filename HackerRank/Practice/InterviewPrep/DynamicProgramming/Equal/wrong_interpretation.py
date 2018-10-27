# use this as the main template for python problems
from collections import Counter

        
def string_to_dict(d, a):

    for i in a:
        ac = ord(i)
        if(ac in d):
            d[ac] += 1
        else:
            d[ac] = 1


if __name__ == "__main__":

    # single variables
    q = [int(val) for val in input().split()][0]

    diff = 32
    for i in range(q):

        a = [str(val) for val in input().split()][0]
        b = [str(val) for val in input().split()][0]

        da = {}
        db = {}

        string_to_dict(da, a)
        string_to_dict(db, b)


        # strategy is to get get a dict which contains the following:
        # each key is an ascii code 
        # only store key for upper case letters
        # each val is a tuple (number of uppercase letters, number of lower case letters)
        # the conversion is done using diff (32)

        # the follwing details the solution
        # if there is more of a capital in A, then the answer is NO
       
        new_da = {} 
        pos = True
        for key, count in da.items():
            if(key < 97):
                new_da[key] = [count, 0 if not (key+diff) in da else da[key+diff]]
                if(not key in db or count > db[key]):
                    pos = False
                    break
            else:
                new_da[key-diff] = [0 if not (key-diff) in da else da[key-diff], count]

        da = new_da
        if(pos):
            for key, count in db.items():
                if(not key in da):
                    pos = False
                    break
                
                if(da[key][0] > db[key]):
                    pos = False
                    break
            
                if(sum(da[key]) < db[key]):
                    pos = False
                    break
            
    
        if(pos):
            print("YES")
        else:    
            print("NO")
                                        


