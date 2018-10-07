# use this as the main template for python problems

from collections import Counter
from itertools import combinations_with_replacement


if __name__ == "__main__":

    # single variables
    exp = input()
    
    # stategy: convert to parenthesis expression
    minus = []
    par_exp = ''
    for i in exp:
        if(i == '-'):
            minus.append(True)
        elif(i == '+'):
            minus.append(False)
        elif(i == '?'):
            
            if(len(minus) and minus[-1] != None):
                par_exp += '('
            
            par_exp += i

            if(len(minus) and minus[-1] == None):
                while(len(minus) and minus[-1] == None):
                    par_exp += ')'
                    minus.pop() 
                continue 
            
            if(len(minus)):
                par_exp += '-' if minus[-1] else '+'
                minus[-1] = None
    
    # do some trimming
    if(par_exp[0] == '('):
        par_exp = par_exp[1:]
    if(par_exp[-1] == ')'):
        par_exp = par_exp[:-1]
    
    # convert to no parenthesis
    fexp = ''
    minus = []
    recent = None
    for i in par_exp:
        if(i == '?'):
            fexp += i    
        elif(i == '+'):
            if(len(minus) and minus[-1]):
                fexp += '-'
            else:
                fexp += '+'
            recent = False
        elif(i == '-'):
            if(len(minus) and minus[-1]):
                fexp += '+'
            else:
                fexp += '-'
            recent = True
        elif(i == '('):
            if(recent == None or recent == False):
                if(len(minus)):
                    minus.append(minus[-1] or False)
                else:
                    minus.append(False)
            else:
                if(len(minus)):
                    minus.append(not (minus[-1] == True))
                else:
                    minus.append(True)
        

    fexp = fexp.replace('?', '')
    counter = Counter(fexp)
    plus_count = counter['+']
    minus_count = counter['-']
    diff = abs(plus_count - minus_count)
    print(fexp)

    # we need three things
    # 1. the largest
    # 2. how many of the largest to use
    
    print(minus_count, plus_count)
    from math import ceil
    if(plus_count > minus_count):
        largest = ceil(float(diff) / float(minus_count + 1))
        must_be_largest = diff % (minus_count + 1)
        met = 0
        print(1)
        for i in fexp:
            if(i == '-'):
                if(met == must_be_largest and largest != 1):
                    print(largest - 1)
                else:
                    print(largest)
                    met += 1
            if(i == '+'):
                print(1)

    elif(minus_count > plus_count):
        largest = ceil(float(diff) / float(plus_count + 1))
        must_be_largest = diff % (plus_count + 1)
        met = 1
        print(largest)
        for i in fexp:
            if(i == '+'):
                if(met == must_be_largest and largest != 1):
                    print(largest - 1)
                else:
                    print(largest)
                    met += 1
            if(i == '-'):
                print(1)
    else:
        print(1)
        met = False
        for i in fexp:
            if(i == '+'):
                print(1)
            elif(met):
                print(1)
            else:
                print(2)
                met = True
                

        
