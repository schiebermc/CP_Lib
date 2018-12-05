if __name__ == "__main__":

    n = 2000
    f = open("stuff.txt", "w")
    f.write("%d\n" % (n))
    for i in range(n):
        f.write("0 ")
    f.close()
