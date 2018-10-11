# use this as the main template for python problems


if __name__ == "__main__":

    # single variables
    t = [int(val) for val in input().split()][0]

    for i in range(t):

        # vectors
        s, a, b, c = [int(val) for val in input().split()]

        amount = (s//c)
        print(amount + (amount//a)*b)



