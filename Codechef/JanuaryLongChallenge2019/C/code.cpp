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


int main() {

    ll n, m, val;
    cin >> n >> m;
   
    map<ll, ll> a; 
    map<ll, ll> b;
    for(ll i=0; i<n; i++) {
        scanf("%lld", &val);
        a[val] = i;
    }
    for(ll i=0; i<m; i++) {
        scanf("%lld", &val);
        b[val] = i;
    }

    auto val2 = b.begin()->second;
    for(auto & kv : a) 
        printf("%lld %lld\n", kv.second, val2);
   
    auto val1 = a.rbegin()->second; 
    auto itr = b.begin(); itr++;
    while(itr != b.end()) {
        printf("%lld %lld\n", val1, itr->second);
        itr++;
    }

    return 0;
}


