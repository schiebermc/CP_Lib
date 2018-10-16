# use this as the main template for python problems
import sys

def solution(q):

    placed = False;
    lind = 0;
    rind = 0;
    book_map = {};
    for i in range(q):
        
        op, book_ind = [val for val in sys.stdin.readline().split()]
        book_ind = int(book_ind)

        if(op == 'R'):
            book_map[book_ind] = rind;
            rind += 1;
            if(not placed):
                placed = True;
                lind -= 1;

        elif(op == 'L'):
            book_map[book_ind] = lind;
            lind -= 1;
            if(not placed):
                placed = True;
                rind += 1;
            
        elif(op == '?'):
            ldist = book_map[book_ind] - lind;
            rdist =  rind - book_map[book_ind];
            print(min(ldist, rdist) - 1);


if __name__ == "__main__":

    q = [int(val) for val in sys.stdin.readline().split()][0]
    solution(q);
    




