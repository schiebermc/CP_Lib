import sys
sys.setrecursionlimit(2000)
from collections import Counter


def closest(mid, vec):


if __name__ == "__main__":

    # single variables
    n, m, cs, ce, v = [int(val) for val in input().split()]

    s = [int(val) for val in input().split()]
    e = [int(val) for val in input().split()]
    
    q = [int(val) for val in input().split()][0]

    # n and m are on the order of 10^8, so any graph solution
    # is out of the question.

    for i in range(q):
        
        x1, y1, x2, y2 = [int(val) for val in input().split()]

        # if x1 == x2, same floor, so no stair or elevator are needed
        if(x1 == x2):
            print(abs(y1 - y2))


        # the hotel is a freaking rectangle!!
        # otherwise, located the closest stair or elevator to the 
        # intersection of y1 and y2
        if(y1 > y2):
            mid = float(y2) + float(y1 - y2) / 2.;
        else
            mid = float(y1) + float(y2 - y1) / 2.;
        
    
        best_s = closest(mid, s);
        best_e = closest(mid, e);
        
        #etime = ll(ceil(float(abs(x2 - x1)) / float(v))) + abs(best_e - y1) + abs(best_e - y2); 
        #stime = abs(x2 - x1) + abs(best_s - y1) + abs(best_s - y2); 
        



