import sys
from itertools import permutations

if __name__ == "__main__":

    # read input
    cross = []
    for i in range(10):
        cross.append([val for val in input().strip()])
    words = input().split(';')

    # get all starting points
    points = []
    for i in range(10):
        for j in range(10):
            if((j-1 == -1 or cross[i][j-1] == '+') and cross[i][j] =='-' and j+1 != 10 and cross[i][j+1] == '-'):
                points.append((i, j, 'r'))

            if((i-1 == -1 or cross[i-1][j] == '+') and cross[i][j] =='-' and i+1 != 10 and cross[i+1][j] == '-'):
                points.append((i, j, 'd'))
          
            # special points of just 1 char
            if((j-1 == -1 or cross[i][j-1] == '+') and (i-1 == -1 or cross[i-1][j] == '+') and
                (j+1 == 10 or cross[i][j+1] == '+') and 
                (i+1 == 10 or cross[i+1][j] == '+') and cross[i][j] == '-'):
                points.append((i, j, 's'))

    # sanity check
    assert len(points) == len(words)
   
    from copy import deepcopy
    # just try all combos of words and points until it works
    for perm in permutations(points):
        pos = True
        new_cross = deepcopy(cross)
        
        for ind1, word in enumerate(words):
            i1, j1, t = perm[ind1]
            ind2 = 0 
            while(ind2 != len(word)):
                char = word[ind2]
                i2, j2 = i1, j1
                if(t == 'r'):
                    j2 += ind2
                else:
                    i2 += ind2
                
                if(i2 == 10 or j2 == 10 or new_cross[i2][j2] != '-' and new_cross[i2][j2] != char):
                    pos = False
                    break
                new_cross[i2][j2] = char
                ind2 += 1

            if(ind2 != len(word)):
                pos = False
                break
    
        if(pos):
            break 

    print(pos)
    for row in new_cross:
        for char in row:
            print(char, end='')
        print('')

                
 
