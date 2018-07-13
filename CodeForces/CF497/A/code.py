
import sys

if __name__ == "__main__":

    vowels = "aeiou"
    consts = "bcdfghjklmnpqrstvwzyz"

    word = sys.stdin.readline()
    word = word.rstrip('\n')

    good = True
    for i in range(len(word)-1):
        if(word[i] in vowels or word[i] == 'n'):
            pass
        elif(word[i+1] in vowels):
            pass
        else:
            good = False
            break
    
    if(good):
        if(word[-1] in vowels or word[-1] == 'n'):
            pass
        else:
            good = False
    
    if(good):
        print("YES")
    else:
        print("NO") 
