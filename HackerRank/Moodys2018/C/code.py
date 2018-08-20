if __name__ == "__main__":

    super_summ = 0
    total_stocks = 0

    n = [int(val) for val in input().split()][0]
    stocks = []; 
    averages = []
 
    for i in range(n):
        
        m = [int(val) for val in input().split()][0]
        total_stocks += m;
        
        stocks.append([int(val) for val in input().split()])
        
        summ = 0;
        for j in range(m):
            summ += stocks[i][j];
            super_summ += stocks[i][j];
        averages.append(summ / m)

    super_average = super_summ / total_stocks;
    best_diff = float('inf');

    for x in averages:
        diff = abs(super_average - x);
        if(best_diff > diff):
            best_diff = diff;
            best_x = x;

    ans = 0.0;
    for vec in stocks:
        for x in vec:
            ans += abs(x - best_x);
    print(ans)

