import matplotlib.pyplot as plt

N = 500
D = 11

if __name__ == "__main__":

    Y = []
    X = range(1, N, D)
    for i in X:
        Y.append(sum([int(val) for val in str(i)]))

    print(X)
    plt.plot(X, Y)
    plt.show()

