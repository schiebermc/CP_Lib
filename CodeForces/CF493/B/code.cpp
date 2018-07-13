//#include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <ctime>

using namespace std;

typedef long long int ll;

ll cuts(ll count, ll ind, ll n, ll m, ll co, ll ce, vector<ll>& a);
ll solution1(ll n, ll m, vector<ll>& a);
ll solution2(ll n, ll m, vector<ll>& a);

ll solution(ll n, ll m, vector<ll>& a){

    return solution2(n, m, a);    

}

ll solution1(ll n, ll m, vector<ll>& a){

    return cuts(0, 0, n, m, 0, 0, a);    

}

ll solution2(ll n, ll m, vector<ll>& a){

    vector<vector<ll>> P;
    P.push_back({0, m, 0, 0});
    for (ll i=0; i<n-1; i++) {
        ll x1 = a[i];
        ll x2 = a[i+1];
        bool odd = (x1%2 == 1);
        ll current_size = P.size();
        for (ll p=0; p<current_size; p++) {
            if(odd) {
                P[p][3] += 1;
            } else {
                P[p][2] += 1;
            }
            if(P[p][2] == P[p][3]) {
                if(abs(x1 - x2) <= P[p][1]) {
                    P.push_back({P[p][0] + 1, P[p][1] - abs(x1 - x2), 0, 0});
                }
            }
        }
    }
    ll best = 0;
    for (auto &p : P) {
        if(p[0] > best) 
            best = p[0];
    }
    return best;
}

    
ll cuts(ll count, ll ind, ll n, ll m, ll co, ll ce, vector<ll>& a) {
    for (ll i=ind; i<n; i++) {
        if(a[i]%2 == 0) {
            ce++;
        } else {
            co++;
        }
        if(co == ce and i != n-1 and (m >= abs(a[i] - a[i+1]))) {
            ll val1 = cuts(count+1, i+1, n, m - abs(a[i] - a[i+1]), 0, 0, a);
            ll val2 = cuts(count, i+1, n, m, co, ce, a);
            return max(val1, val2);
        }
    }
    return count;
}

void validation2(ll n) {

    float T1 = 0.0;
    float T2 = 0.0;

    vector<ll> a; a.resize(n);
    for (ll i=0; i<n; i++) {
        a[i] = i+1;
    }
    
    clock_t t1 = clock();
    ll val1 = solution1(n, n, a); 
    clock_t t2 = clock();
    ll val2 = solution2(n, n, a);
    clock_t t3 = clock();
    if(val1 != val2)        
        throw;
    
    T1 = (float)(t2 - t1);
    T2 = (float)(t3 - t2);
    
    printf("T1: %fs\n", T1/1000000);
    printf("T2: %fs\n", T2/1000000);
    return;
}

//void validation(ll n, ll seeds) {
//
//    float T1 = 0.0;
//    float T2 = 0.0;
//
//    vector<ll> a; a.resize(n);
//    for (ll seed=0; seed<seeds; seed++) {
//        srand(seed);
//        ll co = 0;
//        ll ce = 0;
//        for (ll x=0; x<n; x++) {
//            a[x] = rand()%10+1;
//            if(a[x]%2 == 0 ) {
//                ce++;
//            } else { 
//                co++;
//            }
//        }
//        ll ind = 0;
//        if(co > ce) {
//            while(co > ce) {
//                if(a[ind] % 2 == 1) {
//                    a[ind] -= 1;
//                    ce++;
//                    co--;
//                }
//                ind++;
//            }
//        } else if (ce > co ) {
//            while(ce > co) {
//                if(a[ind] % 2 == 0) {
//                    a[ind] -= 1;
//                    ce--;
//                    co++;
//                }
//                ind++;
//            }
//        }
//        ll m = rand()%10;
//        clock_t t1 = clock();
//        ll val1 = solution1(n, m, a); 
//        clock_t t2 = clock();
//        ll val2 = solution2(n, m, a);
//        clock_t t3 = clock();
//        if(val1 != val2)        
//            throw;
//        
//        T1 += (float)(t2 - t1);
//        T2 += (float)(t3 - t2);
//
//    }
//    printf("T1: %fs\n", T1/1000000);
//    printf("T2: %fs\n", T2/1000000);
//    return;
//}

int main() {

    // variables
    ll n, m;
    cin >> n >> m;

    vector<ll> arr; arr.resize(n);
    for(ll i=0; i<n; i++) {
        scanf("%lld", &arr[i]);
    }
    
    validation2(50);
    //printf("%lld\n", solution(n, m, arr));
    
    return 0;
}

