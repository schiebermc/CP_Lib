import sys
sys.setrecursionlimit(2000)
from collections import Counter
import math
from functools import reduce


if __name__ == "__main__":

    # single variables
    h = [int(val) for val in input().split()][0]
    m = [int(val) for val in input().split()][0]

    hm = {1 : 'one', 2 : 'two', 3 : 'three', 4 : 'four' , 5 : 'five', 6 : 'six', 
         7 : 'seven', 8 : 'eight', 9 : 'nine', 10 : 'ten', 11: 'eleven', 12 : 'twelve'}

    mins = ["zero", 
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen",
        "twenty",
        "twenty one",
        "twenty two",
        "twenty three",
        "twenty four",
        "twenty five",
        "twenty six",
        "twenty seven",
        "twenty eight",
        "twenty nine"]

    if(m > 30):
        h = h+1 if h != 12 else 0

    if(m == 0):
        s = hm[h] + "o' clock"
    
    elif(m == 15):
        s = 'quarter past ' + hm[h]

    elif(m == 30):
        s = 'half past ' + hm[h]

    elif(m == 45):
        s = 'quarter till ' + hm[h]

    elif(m < 30):
        s = mins[m] + ' minutes past ' + hm[h]

    else:
        s = 60-mins[m] + ' to ' + hm[h]

    print(s)
        




