import sys

if __name__ == "__main__":

    # single variables
    T = [int(val) for val in input().split()][0]

    for test_case in range(T):
            
        n = [int(val) for val in input().split()][0]
        result = []
        for i in range(n):
            print("%d %d %d %d" % (1, i+1, i+1, i+1))
            sys.stdout.flush()
            val = [int(val) for val in input().split()][0]
            result.append(val)
            if(val == -1):
                fuck

        print("2 ", end='')
        for i in result:
            print("%d " % (i), end='')
        print('')
        sys.stdout.flush()

        val = [int(val) for val in input().split()][0]
        if(val == -1):
            fuck


