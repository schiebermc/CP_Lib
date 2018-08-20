//#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <set>
#include <float.h>

using namespace std;

typedef long long int ll;

double solution1(ll n, ll super_summ, ll total_stocks, vector<ll> stocks, vector<double> averages) {
    // SOLUTION USING MEAN - INCORECT

    double super_average = (double)super_summ / (double)total_stocks;
    double best_diff = DBL_MAX;
    double diff, best_x;

    for(auto x : averages) {
        diff = abs(super_average - x);
        if(best_diff > diff) {
            best_diff = diff;
            best_x = x;
        }
    }

    //printf("super_average: %f\n", super_average);
    //printf("best_x : %f\n", best_x);
    double ans = 0.0;
    for(auto &x : stocks) {
        ans += abs(x - best_x);
    }
    return ans;
}

double solution3(ll n, ll super_summ, ll total_stocks, vector<ll> stocks, vector<double> averages) {
    // SOLUTION USING MEDIAN - ?

    double super_median;
    sort(stocks.begin(), stocks.end()); // performance bottleneck
    if(total_stocks%2)
        super_median = stocks[total_stocks/2];
    else
        super_median = (stocks[total_stocks/2] + stocks[total_stocks/2 - 1]) / 2;

    double best_diff = DBL_MAX;
    double diff, best_x;

    for(auto x : averages) {
        diff = abs(super_median - x);
        if(best_diff > diff) {
            best_diff = diff;
            best_x = x;
        }
    }

    //printf("super_median: %f\n", super_median);
    //printf("best_x : %f\n", best_x);
    double ans = 0.0;
    for(auto &x : stocks) {
        ans += abs(x - best_x);
    }
    return ans;
}

double solution2(ll n, ll super_summ, ll total_stocks, vector<ll> stocks, vector<double> averages) {
    // BRUTE FORCE SOLUTION - CORRECT BUT SLOW    

    double best = DBL_MAX;
    for (auto this_x : averages) {
        double ans = 0.0;
        for(auto &x : stocks) {
            ans += abs(x - this_x);
        }
        //if(ans < best) 
        //    printf("this best average: %f\n", this_x);
        best = (ans < best ? ans : best);
    }
    return best;
}

void validation(ll start_seed, ll end_seed, ll n, ll m_max, ll stock_max) {

    for(ll s=start_seed; s<=end_seed; s++) {
        srand(s);
    
        ll m, summ, super_summ = 0, total_stocks = 0;
        
        vector<ll> stocks;
        vector<double> averages; averages.resize(n);   
 
        for(ll i=0; i<n; i++) {
            m = rand()%m_max + 1;
            total_stocks += m;
            stocks.resize(total_stocks);
            for(ll j=total_stocks-m; j<total_stocks; j++) {
                stocks[j] = rand()%stock_max+1;
            }
            summ = 0;
            for(ll j=total_stocks-m; j<total_stocks; j++) {
                summ += stocks[j];
                super_summ += stocks[j];
            }
            averages[i] = (double)summ / (double)m;
        }

        //printf("stocks: \n");
        //for (auto x : stocks) {
        //    printf("%lld, ", x);
        //    printf("\n");
        //}

        //printf("averages: \n");
        //for (auto x : averages) {
        //    printf("%f, ", x);
        //}
        //printf("\n");

        double ans1 = solution3(n, super_summ, total_stocks, stocks, averages);
        double ans2 = solution2(n, super_summ, total_stocks, stocks, averages);

        if(abs(ans1 - ans2) > 1e-6)
            printf("seed: %lld - %f, %f\n", s, ans1, ans2);
    }

}

int main() {

    //validation(0, 10, 5, 5, 10); 
    
    ll n, m, summ, super_summ = 0, total_stocks = 0;
    cin >> n;
    
    vector<ll> stocks;
    vector<double> averages; averages.resize(n);   
 
    for(ll i=0; i<n; i++) {
        scanf("%lld", &m);
        total_stocks += m;
        stocks.resize(total_stocks);
        for(ll j=total_stocks-m; j<total_stocks; j++) {
            scanf("%lld", &stocks[j]);
        }
        summ = 0;
        for(ll j=total_stocks-m; j<total_stocks; j++) {
            summ += stocks[j];
            super_summ += stocks[j];
        }
        averages[i] = (double)summ / (double)m;
    }

    //vector<vector<ll>> stocks; stocks.resize(n);
    //vector<double> averages; averages.resize(n);   
 
    //for(ll i=0; i<n; i++) {
    //    cin >> m;
    //    stocks[i].resize(m);
    //    total_stocks += m;
    //    for(ll j=0; j<m; j++) {
    //        scanf("%lld", &stocks[i][j]);
    //    }
    //    summ = 0;
    //    for(ll j=0; j<m; j++) {
    //        summ += stocks[i][j];
    //        super_summ += stocks[i][j];
    //    }
    //    averages[i] = (double)summ / (double)m;
    //}

    double ans = solution3(n, super_summ, total_stocks, stocks, averages);
    printf("%f\n", ans);
    return 0;
}

