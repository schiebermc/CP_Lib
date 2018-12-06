import sys
sys.setrecursionlimit(2000)
from collections import Counter

def solution(n, m, a):

    bt = BitTrie(32)

    for i in a:
        bitstring = bt.get_bitstring_from_int(i)
        bt.add_bitstring(bitstring)

    for i in range(m):
        val = [int(val) for val in input().split()][0]
        bitstring = bt.get_bitstring_from_int(val)
        print(bt.get_max_XOR(bitstring))
 

class BitTrie:
    # stores a list of bitstrings in a Trie

    def __init__(self, n):

        self.n = n
        self.tree = {}


    def add_bitstring(self, bitstring):
        # assumes bitstring is of size n
        # if not use get_bitstring_from_int!
        assert len(bitstring) == self.n
        self._add_bitstring_recursive(bitstring, 0, self.tree)
            
    
    def _add_bitstring_recursive(self, bitstring, level, tree_level):

        if(level == self.n):
            tree_level['bitstring'] = bitstring
            return

        val = bitstring[level]
        
        # update the counts
        if(not 'count' in tree_level):
            tree_level['count'] = [0, 0]
        tree_level['count'][int(val)] += 1

        if(val in tree_level):
            tree_level = tree_level[val]
        else:
            tree_level[val] = {}
            tree_level = tree_level[val]

        self._add_bitstring_recursive(bitstring, level+1, tree_level)


    def get_bitstring_from_int(self, val):
        bit_val = format(val, 'b')
        left_append = ''
        for i in range(self.n - len(bit_val)):
            left_append += '0'
        return left_append + bit_val


    def get_max_XOR(self, bitstring):
        tree_level = self.tree
        for level in range(self.n):
            val = '1' if bitstring[level] == '0' else '0'
            if val in tree_level:
                tree_level = tree_level[val]
            else:
                tree_level = tree_level['0' if val == '1' else '1']

        return int(bitstring, 2) ^ int(tree_level['bitstring'], 2)


if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]

    # vectors
    a = [int(val) for val in input().split()]
    m = [int(val) for val in input().split()][0]
    
    # solve it!
    solution(n, m, a)



