# use this as the main template for python problems
from collections import Counter


if __name__ == "__main__":

    # single variables
    n, m = [int(val) for val in input().split()]

    harmony = [set([]) for i in range(n)]
    for i in range(m):
        
        # get the pair 
        a, b = [int(val) for val in input().split()]
        a -= 1
        b -= 1
        harmony[a].add(b)
        harmony[b].add(a)
   
    pos = [[] for i in range(n)] 

    # each color gets a unique column
    # all intra harmony will be within a column
    # all inter harmony will be within rows
    # the board is sparse enough this should work
    
    v = 1
    vertical_positions = {}
    for i in range(n):

        s = harmony[i]
        count = len(s)
        vertical_positions[i] = set([])

        if(count == 0):
            vertical_positions[i].add(v)
            pos[i].append((i+1, v))
            v += 1
        else:
            for color in s:
                if(color < i):
                    val = vertical_positions[color].pop()
                    pos[i].append((i+1, val))
                else:
                    vertical_positions[i].add(v)
                    pos[i].append((i+1, v))
                    v += 1
       
    print(vertical_positions) 
    for i in pos:
        print(len(i))
        for j in i:
            print(j[0], j[1])

    

