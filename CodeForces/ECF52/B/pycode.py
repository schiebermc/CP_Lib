# use this as the main template for python problems

def solution(n, m):
    
    # edge case
    if(m == 0):
        print("%d %d" % (n, n))
        return

    if(n == 1):
        print("%d %d" % (1, 1))
        return

    # connect one to one
    minn = max(0, n - 2*m)
    
    # totally connected for subgraph
    nodes = 1
    while((nodes-1)*nodes/2 < m):
        nodes += 1
    maxx = max(0, n - nodes)

    print("%d %d" % (minn, maxx))


if __name__ == "__main__":

    # single variables
    n, m = [int(val) for val in input().split()]
    solution(n, m)

