# use this as the main template for python problems

class queue(object):

    def __init__(self):
        self.s1 = []
        self.s2 = []

    def push(self, val):
        self.s1.append(val)

    def pop(self):
        if(len(self.s2) == 0): # form dequeue stack
            while(len(self.s1) != 0):
                self.s2.append(self.s1.pop(0))

        return self.s2.pop(0)
        
    def front(self):
        if(len(self.s2) == 0): # form dequeue stack
            while(len(self.s1) != 0):
                self.s2.append(self.s1.pop(0))
        return self.s2[0]

if __name__ == "__main__":

    # single variables
    n = [int(val) for val in input().split()][0]

    q = queue()
    for i in range(n):
        
        # vectors
        query = input().split()

        if(query[0] == '1'):
            q.push(query[1])
        elif(query[0] == '2'):
            q.pop()
        else:
            print(q.front())




