# use this as the main template for python problems
import sys
sys.setrecursionlimit(2000)
from collections import Counter

def traversal(tree, node=1, path=None):
    
    if(path == None):
        path = []
    
    if(tree[node][0] != -1):
        traversal(tree, tree[node][0], path)

    path += [node]
    
    if(tree[node][1] != -1):
        traversal(tree, tree[node][1], path)

    return path    

def get_depths(tree, node=1, depth=1, depths=None):
    if(depths == None):
        depths = {}
    
    if(tree[node][0] != -1):
        get_depths(tree, tree[node][0], depth+1, depths)

    if(depth in depths):
        depths[depth].append(node)
    else:
        depths[depth] = [node]
 
    if(tree[node][1] != -1):
        get_depths(tree, tree[node][1], depth+1, depths)

    return depths 
    

if __name__ == "__main__":

    tree = {}

    # single variables
    n = [int(val) for val in input().split()][0]

    for i in range(1, n+1):
    
        a, b = [int(val) for val in input().split()]
        tree[i] = (a, b)

    depths = get_depths(tree)
    max_depth = max([key for key in depths])   

    t = [int(val) for val in input().split()][0]
    
    for q in range(t):

        k = [int(val) for val in input().split()][0]
   
        for depth in range(k, max_depth+1, k):
            for node in depths[depth]: 
                lc, rc = tree[node]
                tree[node] = (rc, lc)

        path = traversal(tree)


        for i in path:
            print("%d " % i, end='')

        print("")
