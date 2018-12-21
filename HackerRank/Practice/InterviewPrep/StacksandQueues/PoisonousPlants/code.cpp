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


void solution(ll n, vector<ll>& a){

    ll days = 0;
    set<ll> inds;
    for (ll i=0; i<n; i++)
        inds.emplace(i);
    while(true){
        bool good = true;
        auto itr = inds.begin();
        ll prev_val = a[*itr];
        itr++;
        while(itr != inds.end()) {
            ll val = a[*itr];
            if(val > prev_val){
                itr = inds.erase(itr);
                itr--;
                good = false;
            }
            prev_val = val;
            itr++;
        }
        printf("%lld\n", days-1); 
        days += 1;
        if(good)
            break;
    }
    printf("%lld\n", days-1); 
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

