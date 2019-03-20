from random import randint

class SneakySet():

    def __init__(self, n):

        self.A = [val for val in range(n)]
        self.D = {val : val for val in self.A}
        self.n = n
        
    def contains(self, val):
        return val in D

    def random_choice(self):
        ind = randint(0, self.n-1)
        return self.A[ind]

    def remove_val(self, val):
        last = self.A[-1]
        self.A[self.D[val]] = last
        self.D[last] = self.D[val]
        del self.D[val]
        del self.A[-1]
        self.n -= 1

if __name__ == "__main__":

    N = 7

    print("set: ")
    s = set(range(N))
    for i in range(N):
        print(s.pop())

    print("sneaky set: ")
    S = SneakySet(N)
    for i in range(N):
        val = S.random_choice()
        S.remove_val(val)
        print(val)

