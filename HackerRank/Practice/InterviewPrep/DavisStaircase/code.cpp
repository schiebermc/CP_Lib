//#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <set>
#include <climits>

using namespace std;

typedef long long int ll;

ll MOD = 10000000007;

ll ways(ll height, map<ll, ll>& records); 

ll mod_plus(ll val1, ll val2) {
    return ( (val1 % MOD) + (val2 % MOD) ) % MOD;
}

void solution(ll n, vector<ll> a){

    map<ll, ll> records;
    for(auto x : a) {
        ll ans = ways(x, records);
        printf("%lld\n", ans);
    }

}

ll ways(ll height, map<ll, ll>& records) {

    if(records.find(height) != records.end())
        return records[height];
    if(height < 0)
        return 0;
    if(height == 0) 
        return 1;

    ll count = 0;
    for( ll x : {1, 2, 3}) {
        count = mod_plus(count, ways(height-x, records));
    }
    records[height] = count;
    return count;
}

int main() {

    // variables
    ll n;
    cin >> n;

    vector<ll> arr; arr.resize(n);
    for(ll i=0; i<n; i++) {
        scanf("%lld", &arr[i]);
    }
    
    solution(n, arr);
    
    return 0;
}

