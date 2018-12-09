import sys

def bitstring(val, size):
    b = bin(val)[2:]
    rem = size - len(b)
    return '0'*rem + b 
    
def gen_possibilities(indexes, summ):
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

def determine_a(a, answers, trips, size, n):
    # each column can be solved independently 
    # these are bitwise operations, after all.
    # the thought is to have 3 equations for each bit that be must solve for
    # each equation involves 3 unknowns. 
    # however, each equation can have 2 RHS, so i employ recursion with
    # backtracking to arrive at a solution.
    for col in range(size-1, -1, -1):
        determine_column_recursive(a, answers, trips, col, 0, size, n)


def determine_column_recursive(a, answers, trips, col, ind, size, n):

    if(ind == n):
        # one final check
        i, j, k = trips[-1]  
        summ = 0
        for row in [i, j, k]:
            summ += int(a[row][col])
        answer = trips[-1]
        if(answer == 0):
            summs = [0, 2]
        elif(answer == 1):
            summs = [1, 3]
        else:
            raise Exception()
        if(not summ in summs):
            return False
        return True

    i, j, k = trips[ind]
    answer = int(answers[ind][col])
   
    if(answer == 0):
        summs = [0, 2]
    elif(answer == 1):
        summs = [1, 3]
    else:
        raise Exception()
    
    if(i == 0):
        indexes = 3
    elif(i == n-1 or j == n-1):
        indexes = 0
    else:
        indexes = 1
    
    pos = True
    if(indexes != 0):

        psumm = 0
        for row in [i, j, k][:3-indexes]:
            psumm += int(a[row][col])
        
        pos = False
        for summ in summs:
            p = gen_possibilities(indexes, summ - psumm)
            if(len(p) == 0):
                pos = False
            else:
                for bins in p:
                    for IND, row in enumerate([i, j, k][3-indexes:]):
                        a[row][col] = str(bins[IND])
                        
                    pos = determine_column_recursive(a, answers, trips, col, ind+1, size, n)
                    if(pos):
                        break
                    for IND, row in enumerate([i, j, k][3-indexes:]):
                        a[row][col] = '0'
                            
            if(pos):
                break

    # one final check
    summ = 0
    for row in [i, j, k]:
        summ += int(a[row][col])

    if(not summ in summs):
        return False

    if(ind == n-1):
        return pos
    else:
         return determine_column_recursive(a, answers, trips, col, ind+1, size, n)

    
def int_from_bitlist(bitlist):
    
    result = 0
    n = len(bitlist)
    for ind, val in enumerate(bitlist):    
        if(val == '1'):
            result += 2**(n-1-ind)
    return result


if __name__ == "__main__":

    # single variables
    T = [int(val) for val in input().split()][0]
    size = 32

    for test_case in range(T):
            
        # size of problem
        n = [int(val) for val in input().split()][0]
        
        # prepare and answer matrix (a) and the queries to ask 
        a = []
        trips = []
        for i in range(n):
            ind1 = i
            ind2 = 0 if i+1 == n else i+1
            ind3 = i+2
            ind3 = 0 if ind3 == n else ind3
            ind3 = 1 if ind3 == n+1 else ind3
            trips.append((ind1, ind2, ind3))
            a.append(['0']*size)

        # ask the queries, log the answers given by the judge
        answers = []
        for i, j, k in trips:
            print("%d %d %d %d" % (1, i+1, j+1, k+1))
            sys.stdout.flush()
            ans = [int(val) for val in input().split()][0]
            if(ans == -1):
                raise Exception("somthing went horribly horribly wrong")
            answers.append(bitstring(ans, size))

        # where all the magic happens
        determine_a(a, answers, trips, size, n)

        # the sequence has been determine, convert back then print
        result = []
        for i in a:
            result.append(int_from_bitlist(i))
        print("2 ", end='')
        for i in result:
            print("%d " % (i), end='')
        print('')
        sys.stdout.flush()



