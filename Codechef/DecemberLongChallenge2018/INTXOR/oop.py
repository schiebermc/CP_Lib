import sys

class Solver():

    def __init__(self, n, size):
        self.n = n
        self.size = size
        # prepare and answer matrix (a) and the queries to ask 
        self.a = []
        self.trips = []
        self.answers = []
        for i in range(n):
            ind1 = i
            ind2 = 0 if i+1 == n else i+1
            ind3 = i+2
            ind3 = 0 if ind3 == n else ind3
            ind3 = 1 if ind3 == n+1 else ind3
            self.trips.append((ind1, ind2, ind3))
            self.a.append(['0']*size)
    
    def gen_possibilities(self, indexes, summ):
        # generates all posibly bit combinations based on
        # the number of bits and how much the bits should sum to
        if(indexes == 3):
            if(summ == 0):
                return [(0, 0, 0)]
            elif(summ == 1):
                return [(0, 0, 1), (0, 1, 0), (1, 0, 0)]
            elif(summ == 2):
                return [(1, 1, 0), (1, 0, 1), (0, 1, 1)]
            elif(summ == 3):
                return [(1, 1, 1)]
            else:
                raise Exception()
        if(indexes == 1):
            if(summ == 0):
                return [[0]]
            elif(summ == 1):
                return [[1]]
            else:
                return []
    
    def determine_a(self):
        # each column can be solved independently 
        # these are bitwise operations, after all.
        # the thought is to have 3 equations for each bit that be must solve for
        # each equation involves 3 unknowns. 
        # however, each equation can have 2 RHS, so i employ recursion with
        # backtracking to arrive at a solution.
        for col in range(self.size-1, -1, -1):
            self.determine_column_recursive(col, 0)
    
    def determine_column_recursive(self, col, ind):
    
        if(ind == self.n):
            # one final check
            i, j, k = self.trips[-1]  
            summ = 0
            for row in [i, j, k]:
                summ += int(self.a[row][col])
            answer = self.trips[-1]
            if(answer == 0):
                summs = [0, 2]
            elif(answer == 1):
                summs = [1, 3]
            else:
                raise Exception()
            if(not summ in summs):
                return False
            return True
    
        i, j, k = self.trips[ind]
        answer = int(self.answers[ind][col])
       
        if(answer == 0):
            summs = [0, 2]
        elif(answer == 1):
            summs = [1, 3]
        else:
            raise Exception()
        
        if(i == 0):
            indexes = 3
        elif(i == self.n-1 or j == self.n-1):
            indexes = 0
        else:
            indexes = 1
        
        pos = True
        if(indexes != 0):
    
            psumm = 0
            for row in [i, j, k][:3-indexes]:
                psumm += int(self.a[row][col])
            
            pos = False
            for summ in summs:
                p = self.gen_possibilities(indexes, summ - psumm)
                if(len(p) == 0):
                    pos = False
                else:
                    for bins in p:
                        for IND, row in enumerate([i, j, k][3-indexes:]):
                            self.a[row][col] = str(bins[IND])
                            
                        pos = self.determine_column_recursive(col, ind+1)
                        if(pos):
                            break
                        for IND, row in enumerate([i, j, k][3-indexes:]):
                            self.a[row][col] = '0'
                                
                if(pos):
                    break
    
        # one final check
        summ = 0
        for row in [i, j, k]:
            summ += int(self.a[row][col])
    
        if(not summ in summs):
            return False
    
        if(ind == self.n-1):
            return pos
        else:
             return self.determine_column_recursive(col, ind+1)

    def gather_answers(self):
        # ask the queries, log the answers given by the judge
        for i, j, k in self.trips:
            print("%d %d %d %d" % (1, i+1, j+1, k+1))
            sys.stdout.flush()
            ans = [int(val) for val in input().split()][0]
            if(ans == -1):
                raise Exception("somthing went horribly horribly wrong")
            self.answers.append(bitstring(ans, size))
   
    def get_answers(self, arr):
        # this function is only used for validation purposes!
        for i, j, k in self.trips:
            ans = arr[i] ^ arr[j] ^ arr[k]
            self.answers.append(bitstring(ans, self.size))
 
    def give_result(self):
        # the sequence has been determine, convert back then print
        result = []
        for i in self.a:
            result.append(int_from_bitlist(i))
        print("2 ", end='')
        for i in result:
            print("%d " % (i), end='')
        print('')
        sys.stdout.flush()


    def get_result(self):
        result = []
        for i in self.a:
            result.append(int_from_bitlist(i))
        return result 

def int_from_bitlist(bitlist):
    result = 0
    n = len(bitlist)
    for ind, val in enumerate(bitlist):    
        if(val == '1'):
            result += 2**(n-1-ind)
    return result

def bitstring(val, size):
    b = bin(val)[2:]
    rem = size - len(b)
    return '0'*rem + b 


def validation():
    from random import seed
    from random import randint
    n = 15
    size = 32
    for S in range(100):
        seed(S)
        s = Solver(n, size)
        a = [randint(1, 100) for val in range(n)]
        print("seed %d: " % (S), end='')
        s.get_answers(a)
        s.determine_a()
        r = s.get_result()
        passes = True
        for ind, val in enumerate(a):
            passes = passes and val == r[ind]
        
        print(passes)
        if not passes:
            for i, j, k in s.trips:
                print("%d vs %d" % (a[i] ^ a[j] ^ a[k], r[i] ^ r[j] ^ r[k]))

if __name__ == "__main__":

    validation()
#    # single variables
#    T = [int(val) for val in input().split()][0]
#    size = 32
#
#    for test_case in range(T):
#            
#        # size of problem
#        n = [int(val) for val in input().split()][0]
#        
#        # do this problem
#        s = Solver(n, size)
#        s.gather_answers()
#        s.determine_a()
#        s.give_result()
#        
#        # after coding all this up, i got WA bc i didn't realize i had
#        # to do this part.  i love interactive problems :'(
#        val = [int(val) for val in input().split()][0]
#        if(val == -1):
#            fuck
#

