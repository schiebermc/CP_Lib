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

ll solution1(ll N, ll K, vector<ll>& A) {
    
    ll m, count = 0, ind2, X, F;
    for (ll l=0; l<N; l++){
        for(ll r=l; r<N; r++){
            m = ceil(float(K)/float(r - l + 1));
            
            map<ll, ll> c;
            for(ll ind=l; ind<=r; ind++){
                if(c.find(A[ind]) == c.end())
                    c[A[ind]] = 1;
                else
                    c[A[ind]]++;
            }

            ind2 = 0;
            for(auto & kv: c){
                if(ind2 + kv.second*m >= K){
                    X = kv.first;
                    break;
                }
                ind2 += kv.second*m;   
            } 
            
            F = (c.find(X) == c.end() ? 0 : c[X]);
            count += (c.find(F) != c.end() ? 1 : 0);

        }
    }
    return count;
}

int main() {

    ll t;
    cin >> t;

    ll N, K;    
    for(ll test=0; test<t; test++) {

        cin >> N >> K;
        vector<ll> A; A.resize(N);
        for(ll i=0; i<N; i++) {
            scanf("%lld", &A[i]);
        }
        
        printf("%lld\n", solution1(N, K, A));
    }

    return 0;
}


