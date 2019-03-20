import sys

if __name__ == "__main__":

    # single variables
    N = [int(val) for val in sys.stdin.readline().split()][0]

    for i in range(N):
        for val in sys.stdin.readline().replace('\n', ''):
            print(val, ' ', end='')
    print('')    

