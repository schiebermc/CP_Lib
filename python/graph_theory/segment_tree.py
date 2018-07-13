# use this as the main template for python problems

class SegmentTree(object):
    
    # this class was constructed with inspiration and guidance from:
    # https://leetcode.com/articles/a-recursive-approach-to-segment-trees-range-sum-queries-lazy-propagation/
    # O(n) leaves, O(n-1) internal nodes.
    # build:  O(n) :D
    # update: O(k), where k = height of tree :D
    # query:  O(k), where k = height of tree :D
    
    def __init__(self, data, op):
        
        from math import log
        from math import ceil
        
        # The node of the tree is at index 0, thus tree[0] is the root
        # The children of three[i] are tored at tree[2*i+1] and tree[2*i+2]
        # The internal nodes in 
        
        self.n = len(data)
        self.tree = [0] * int(2 * 2 ** (ceil(log(n, 2))) - 1)
        
        self.merge_op = op
       
        self._build_tree(data, 0, 0, self.n-1)
 
    def _build_tree(self, data, ind, lo, hi):
        
        # call as build_tree(data, 0, 0, n-1)
    
        # leaf node, store value
        if (lo == hi):
            self.tree[ind] = data[lo]
            return
        
        # recurse
        mid = lo + (hi - lo) // 2
        self._build_tree(data, 2 * ind + 1, lo, mid)
        self._build_tree(data, 2 * ind + 2, mid + 1, hi)
    
        # merge
        self.tree[ind] = self._merge(self.tree[2 * ind + 1], self.tree[2 * ind + 2])
        
    def _merge(self, val1, val2):
        
        if(self.merge_op == '+'):
            return val1 + val2
        elif(self.merge_op == "OR"):
            return val1 | val2
        elif(self.merge_op == "XOR"):
            return val1 ^ val2
        elif(self.merge_op == "*"):
            return val1 * val2 
 
    def query(self, i, j, ind=0, lo=0, hi=None):
    #def query(self, ind, lo, hi, i, j):
        # call as query(0, 0, n-1, i, j)
        # where i:j is the slice being queried
        if(hi == None):
            hi = self.n-1        

        if (lo > j or hi < i):
            raise Exception()
            return 0 # represents null node completely outside segment
        
        if (i <= lo and j >= hi):
            return self.tree[ind]
        
        mid = lo + (hi - lo) // 2
        
        if (i > mid):
            return self.query(i, j, 2 * ind + 2, mid + 1, hi)
        elif (j <= mid):
            return self.query(i, j, 2 * ind + 1, lo, mid)
        
        lq = self.query(i, mid, 2 * ind + 1, lo, mid)
        rq = self.query(mid + 1, j, 2 * ind + 2, mid + 1, hi)
    
        return self._merge(lq, rq)
    
    def update_value(self, aind, val, tind=0, lo=0, hi=None):
        # call as update_value(0, 0, n-1, i, val)
        # updates value of array index with val
        if(hi == None):
            hi = self.n-1
    
        if (lo == hi):
            self.tree[tind] = val
            return
        
        mid = lo + (hi - lo) // 2 
        
        if (aind > mid):
            self.update_value(aind, val, 2 * tind + 2, mid + 1, hi)
        elif (aind <= mid):
            self.update_value(aind, val, 2 * tind + 1, lo, mid)
            
        self.tree[tind] = self._merge(self.tree[2 * tind + 1], self.tree[2 * tind + 2])


def query_brute_force(a, i, j, op):

    if(op == "+"):
        summ = 0;
        for ind in range(i, j+1):
            summ += a[ind]
        return summ


if __name__ == "__main__":

    # validation
    from random import seed
    from random import randint
    from time import time

    n = 10000
    tests = 100
    seeds = 100

    T1 = 0.0
    T2 = 0.0

    op = '+'

    for s in range(seeds):
    
        seed(s)
        
        a = [randint(-1*n, n) for t in range(n)]

        st = SegmentTree(a, op)
        #st.build_tree(a, 0, 0, len(a)-1)

        test_sieve = []
        while(len(test_sieve) < tests):
            i = randint(0, n-1)
            j = randint(0, n-1)
            if (i <= j):
                test_sieve.append((i, j))

        ind = randint(0, n-1)
        a[ind] = randint(-1*n, n)
        st.update_value(ind, a[ind])

        for ind, test in enumerate(test_sieve):
            i, j = test
            t1 = time()
            val1 = st.query(i, j) 
            t2 = time()
            val2 = query_brute_force(a, i, j, op)
            t3 = time()
            if(val1 != val2):
                raise Exception("Failed test %d with seed %d" % (ind, s))
            T1 += t2 - t1
            T2 += t3 - t2        
             
    print("passed %d tests with %d seeds\n" % (tests*seeds, seeds))
    print(T1)
    print(T2)

