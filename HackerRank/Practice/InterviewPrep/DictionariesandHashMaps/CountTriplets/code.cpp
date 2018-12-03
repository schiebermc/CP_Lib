//#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

typedef long long int ll;

ll solution1(ll n, ll r, vector<ll> a){
    
    // O(N^2)
    // strat: fix the middle term, use one map
    // given that N ~ 10^5, this is not good enough

    ll count = 0.;
    map<ll, ll> hits;
    for(ll i=0; i<n; i++) {
        for(ll j=i+1; j<n; j++) {

            bool good = (a[i]*r == a[j]);
            if(good){
                if(hits.find(j) != hits.end())
                    hits[j]++;
                else
                    hits[j] = 1;
            }

            if(good and hits.find(i) != hits.end())
                count += hits[i];             

            //printf("%lld, %lld, %lld\n", i, j, count);
        }
    }

    return count;
}

ll solution2(ll n, ll r, vector<ll> a){

    // O(Nlog(N))
    // strat: collect singles and doubles on one scan

    bool check;
    ll sval;
    ll count = 0.;
    map<ll, ll> singles;
    map<ll, ll> doubles;
    for(auto val : a) {
 
        // test if a prev value is available
        check = true;
        if(val % r == 0)
            sval = val / r;
        else
            check = false;
        
        if(check) {

            // if prev val is in doubles, then increment count
            if(doubles.find(sval) != doubles.end())
                count += doubles[sval];

            if(singles.find(sval) != singles.end()) {
                if(doubles.find(val) != doubles.end()) 
                    doubles[val] += singles[sval];
                else
                    doubles[val] = singles[sval];
            }       

        }
        
        // store values as they are encountered
        if(singles.find(val) != singles.end())
            singles[val]++;
        else
            singles[val] = 1;

    }

    return count;
}

ll solution3(ll n, ll r, vector<ll> a){

    // O(Nlog(N))
    // strat: collect singles and doubles on one scan

    bool check;
    ll sval;
    ll count = 0.;
    unordered_map<ll, ll> singles;
    unordered_map<ll, ll> doubles;
    for(auto val : a) {
 
        // test if a prev value is available
        check = true;
        if(val % r == 0)
            sval = val / r;
        else
            check = false;
        
        if(check) {

            // if prev val is in doubles, then increment count
            if(doubles.find(sval) != doubles.end())
                count += doubles[sval];

            if(singles.find(sval) != singles.end()) {
                if(doubles.find(val) != doubles.end()) 
                    doubles[val] += singles[sval];
                else
                    doubles[val] = singles[sval];
            }       

        }
        
        // store values as they are encountered
        if(singles.find(val) != singles.end())
            singles[val]++;
        else
            singles[val] = 1;

    }

    return count;
}

void validation(ll start_seed, ll end_seed, ll n) {

    clock_t t0;
    double T0 = 0.0;
    double T1 = 0.0;
    for(ll s=start_seed; s<=end_seed; s++) {
        srand(s);
        vector<ll> a;
        for(ll i=0; i<n; i++) {
            a.push_back(1);//rand()%100);
            while(a[i] == 0)
                a[i] = 1; // rand()%100;
        }
        
        t0 = clock();
        ll val1 = solution2(n, 1, a);
        T0 += double( clock() - t0 ) / (double)CLOCKS_PER_SEC;
        t0 = clock();
        ll val2 = solution3(n, 1, a);
        T1 += double( clock() - t0 ) / (double)CLOCKS_PER_SEC;

        if(val1 != val2) {
            printf("failed at seed: %lld -- %lld !=  %lld\n", s, val1, val2);
        }

    }

    printf("T0: %f\n", T0);
    printf("T1: %f\n", T1);
}

int main() {

    // variables
    ll n, m;
    cin >> n >> m;

    vector<ll> arr; arr.resize(n);
    for(ll i=0; i<n; i++) {
        scanf("%lld", &arr[i]);
    }
    
    //ll ans = solution2(n, m, arr);
    //printf("%lld\n", ans);
    
    validation(0, 0, 100000);
    return 0;
}

