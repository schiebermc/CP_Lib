from random import randint
SIZE = 100
LOWER = 1
UPPER = 100

if __name__ == "__main__":
    
    f = open("input.txt", 'w')
    f.write(str(SIZE) + "\n")

    for i in [randint(LOWER, UPPER) for val in range(SIZE)]:
        f.write("%d " % i)
   
    f.close() 


