import sys
from random import randint

if __name__ == "__main__":

    t = 1
    c = int(1e9)
    print(t)
    sys.stdout.flush()

    for test in range(t):
        
        xl = randint(0, c)
        yl = randint(0, c)
        xu = randint(xl, c)
        yu = randint(yl, c)
    
        q1 = xl + yl
        q2 = 2*c - xu - yu
        q3 = c - yu + xl
        q4 = c - xu + yl
    
        print(q1)
        sys.stdout.flush()
        print(q2)
        sys.stdout.flush()
        print(q3)
        sys.stdout.flush()
        print(q4)
      
        # idk how to make this work! 
        print(yl)
        sys.stdout.flush()

           
         
        
        
          
 
 
