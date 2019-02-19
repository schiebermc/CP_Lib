//#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <bitset>

using namespace std;

typedef long long int ll;

ll solution(ll n, ll p) {
   
    // special cases are n = 1 and n = 2 
    if(n == 1 or n == 2)
        return p*p*p;

//    // scan to determine the max val of N % i
//    ll best = 0;
//    for(ll i=1; i<=p; i++) {
//        ll val = n % i;
//        if(val >= best and val < n)
//            best = val;
//    }
//    
//    // collect all i that result in this maximum value
//    ll inds_count = 0;
//    for(ll i=1; i<=p; i++) {
//        ll val = n % i;
//        if(val == best) 
//            inds_count++;
//    }
    
    //printf("INDS COUNT: %lld --- %lld, %lld, %lld\n", inds_count, n, best, ll(ceil(float(n) / 2.) - 1));
    

    ll best = ll(ceil(float(n) / 2.) - 1);
    ll inds_count = 1;
    // there are three ways to do this.
    // all numbers are less than n
    // first number is unbounded, second two are less than n
    // first two numbers are unbounded, last is less than n

    ll count1 = inds_count*(p - best)*(p - best);
    ll count2 = (p - n)*inds_count*(p - best);
    ll count3 = (p - n)*(p - n)*inds_count;

    return count1 + count2 + count3;

}

ll brute_force(ll n, ll p) {

    ll best = 0;
    for(ll i=1; i<=p; i++) {
        for(ll j=1; j<=p; j++) {
            for(ll k=1; k<=p; k++) {
                ll val = (((n % i) % j) % k) % n;
                best = max(best, val);
            }
        }
    }
    
    ll count = 0;
    for(ll i=1; i<=p; i++) {
        for(ll j=1; j<=p; j++) {
            for(ll k=1; k<=p; k++) {
                ll val = (((n % i) % j) % k) % n;
                if(val == best){
                    count++;
                    //printf("%lld, %lld, %lld\n", i, j, k);
                }
            }
        }
    }
    return count;
}

void validation(ll start_seed, ll end_seed) {

    for(ll s=start_seed; s<=end_seed; s++) {
        srand(s);
        ll p = rand()%100+1;
        ll n = rand()%p+1;
        ll val1 = brute_force(n, p); 
        ll val2 =  solution(n, p);
    
        printf("%lld, %lld, %lld, %lld\n", n, p, val1, val2);    
        if(val1 != val2) {
            printf("failed at seed: %lld .. (n, p, val1, val2) = (%lld, %lld, %lld, %lld)\n", s, n, p, val1, val2);
        
        }

    }
}

int main() {

    ll t, n, p;
    cin >> t;
    
//    validation(0, 100);

    for (ll i=0; i<t; i++) {

        cin >> n >> p;
        //printf("%d\n", solution(n, p) == brute_force(n, p));
        printf("%lld\n", solution(n, p));
        //printf("%lld\n", brute_force(n, p));

    } 
    
    return 0;
}

