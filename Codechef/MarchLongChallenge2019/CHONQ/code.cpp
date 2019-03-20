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

ll solution4(ll n, ll k, vector<ll> a){

    unordered_set<ll> valid;
    for(ll i=0; i<n; i++)
        valid.emplace(i);
    
    ll val;
    for(ll i=0; i<n; i++){
        val = ceil(double(a[i]) / double(k)); 
        for(ll ind=i; i<i-val+1; i--){
            if(valid.find(ind) != valid.end()){
                valid.erase(ind);
            }
        }
    }

    
    ll  pos = n+1;
    for(ll ind=0; ind<n; ind++){
        if(valid.find(ind) == valid.end())
            continue;
        val = 0;
        for(ll i=ind; i<n; i++)
            val += floor(double(a[i]) / double(i-ind+1));
        if(val <= k){
            pos = ind+1;
            break;
        }
    }
    return pos;
}

ll solution5(ll n, ll k, vector<ll> a){

    // how much will a person at position p contribute to total wrath?
    // position i
    // any i > p a[p] will have no affect
    // at i == p the contribution is a[p] / 1
    // at i == p-1 the contribution is a[p] / 2
    // etc..
    // when will a[p] no longer conribute?, or.. when will the contribution be static?
    vector<ll> total(n, 0);
    vector<ll> diffs(n); 
    for(ll i=0; i<n; i++) {
        ll back = sqrt(a[i]);
        for(ll j=i; j>=max(i-back, ll(0)); j--)
            total[j] += floor(double(a[i]) / double(i-j+1));
        while(back > 0){
            ll j = floor(double(a[i]) / back);
            diffs[j-1] += floor(double(a[i]) / j);
            back--;
        }        
    }


    for(ll i=0; i<n; i++) {
        printf("%lld ", diffs[i]);
    }
    printf("\n");
    for(ll i=0; i<n; i++) {
        printf("%lld ", total[i]);
    }
    printf("\n");

    ll p = n+1;
    for(ll i=0; i<n; i++) {
        //printf("%lld -- \n", total[i]);
        if(total[i]<k){
            p = i+1;
            break;
        }
    }
    return p;
}

int main() {    

    ll t;
    cin >> t;
    ll N, K;
    for(ll test=0; test<t; test++){
        
        cin >> N >> K;
        vector<ll> A; A.resize(N);
        for(ll i=0; i<N; i++)
            scanf("%lld", &A[i]);
        
        printf("%lld %lld\n", solution4(N, K, A), solution5(N, K, A));
        //printf("%lld\n", solution5(N, K, A));
    }
        
return 0;
}

