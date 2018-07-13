//#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <set>

using namespace std;

typedef long long int ll;

set<ll> divisors(ll x) {
    ll limit = x;

    set<ll> divs;    
    divs.emplace(1);
    
    ll count = 0;
    if (x == 1) return divs;

    for (ll i = 1; i < limit; ++i) {
        if (x % i == 0) {
            limit = x / i;
            if (limit != i) {
                count++;
                divs.emplace(limit);
            }
            divs.emplace(i);
            count++;
        }
    }

    return divs;
}


ll solution(ll A, ll B, ll C){

    set<ll> divs1 = divisors(A);
    set<ll> divs2 = divisors(B);
    set<ll> divs3 = divisors(C);

    ll best = 0;
    ll count = 0;
    for(auto a : divs1) {
        for(auto b : divs2) {
            if(a > b)
                continue;
            for(auto c : divs3) {
                if(b > c)
                    continue;
                count++;
            }
        }
    }
    best = max(best, count);
    count = 0;
    for(auto a : divs1) {
        for(auto b : divs3) {
            if(a > b)
                continue;
            for(auto c : divs2) {
                if(b > c)
                    continue;
                count++;
            }
        }
    }
    best = max(best, count);
    count = 0;
    for(auto a : divs2) {
        for(auto b : divs1) {
            if(a > b)
                continue;
            for(auto c : divs3) {
                if(b > c)
                    continue;
                count++;
            }
        }
    }
    best = max(best, count);
    count = 0;
    for(auto a : divs2) {
        for(auto b : divs3) {
            if(a > b)
                continue;
            for(auto c : divs1) {
                if(b > c)
                    continue;
                count++;
            }
        }
    }
    best = max(best, count);
    count = 0;
    for(auto a : divs3) {
        for(auto b : divs2) {
            if(a > b)
                continue;
            for(auto c : divs1) {
                if(b > c)
                    continue;
                count++;
            }
        }
    }
    best = max(best, count);
    count = 0;
    for(auto a : divs3) {
        for(auto b : divs1) {
            if(a > b)
                continue;
            for(auto c : divs2) {
                if(b > c)
                    continue;
                count++;
            }
        }
    }
    best = max(best, count);
    return best;

}

void solution2(ll n, ll m, vector<ll> a){

}

void validation(ll start_seed, ll end_seed, ll n) {

    for(ll s=start_seed; s<=end_seed; s++) {
        srand(s);
        vector<ll> a;
        for(ll i=0; i<n; i++) {
            a.push_back(rand()%16);
        }
        //for (auto x : a) {
        //    prllf("%lld, ", x);
        //}
        //prllf("\n");
        //if(solution2(n, a) != solution(n, a)) {
        //    prllf("failed at seed: %lld\n", s);
        //}

    }

}

int main() {

    // variables
    ll t, n, m, k;
    
    cin >> t;
    for(ll i=0; i<t; i++) {
        cin >> n >> m >> k;

        //validation(0, 10, 10)
        printf("%lld\n", solution(n, m, k));
    }
    
    return 0;
}

