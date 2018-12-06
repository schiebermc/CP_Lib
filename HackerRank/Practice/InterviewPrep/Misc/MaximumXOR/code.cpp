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

void solution1(ll n, ll m, vector<ll> a) {

    ll best, val;
    for(ll i=0 ;i< m; i++) {

        cin >> val;
        best = 0;
        for(auto& x : a)
            best = max(best, val ^ x);
        printf("%lld\n", best);

    }

}

void solution2(ll n, ll m, vector<ll> a) {

    vector<string> bits; bits.reserve(n);
    for(auto x : a)
        bits.push_back(bitset<32>(x).to_string());
    sort(bits.begin(), bits.end()); 

    ll best, val;
    for(ll i=0 ;i< m; i++) {

        cin >> val;
        best = 0;
        // get best
        printf("%lld\n", best);

    }

}


int main() {

    // variables
    ll n, m;
    cin >> n;

    vector<ll> arr; arr.resize(n);
    for(ll i=0; i<n; i++) {
        scanf("%lld", &arr[i]);
    }
    
    cin >> m;
    solution2(n, m, arr);   
 
    return 0;
}

