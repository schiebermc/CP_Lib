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

void all_sums_under_k(set<ll>& pos, set<ll>& all_combos, ll k);
void all_sums_under_k_recursive(ll summ, set<ll>& pos, set<ll>& all_combos, ll k);

void solution(ll n, ll k, vector<ll> a){

    set<ll> pos;
    for(ll i=0; i<n; i++) 
        pos.emplace(a[i]%k);
    
    // i think right here i need to generate all sums of these numbers less than k..
    set<ll> all_combos;
    // take care of zero
    if(pos.count(0) != 0){
        all_combos.emplace(0);
        pos.erase(0);
    }
    all_sums_under_k(pos, all_combos, k);

    printf("%lu\n", all_combos.size());
    for(auto x : all_combos) 
        printf("%lld ", x);
    printf("\n");
}

void all_sums_under_k(set<ll>& pos, set<ll>& all_combos, ll k) {
    for(auto x : pos) {
        all_sums_under_k_recursive(x, pos, all_combos, k);
    }
}

void all_sums_under_k_recursive(ll summ, set<ll>& pos, set<ll>& all_combos, ll k) {
    all_combos.emplace(summ % k);
    for(auto x : pos) {
        if(summ + x <= k)
            all_sums_under_k_recursive(summ + x, pos, all_combos, k);
    }
}


int main() {

    // variables
    ll n, m;
    cin >> n >> m;

    vector<ll> arr; arr.resize(n);
    for(ll i=0; i<n; i++) {
        scanf("%lld", &arr[i]);
    }
    
    //validation(0, 10, 10)
    solution(n, m, arr);
    
    return 0;
}

