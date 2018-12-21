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


void solution(ll n, ll s, vector<ll>& a){

    ll total = 0;
    for (auto x : a)
        total += x;
    if(total < s){
        printf("-1\n");
        return;
    }
    map<ll, ll> kegs;
    for(auto x : a){
        if(kegs.find(x) == kegs.end())
            kegs[x] = 1;
        else
            kegs[x]++;
    }

    ll volume = 0;
    while(volume < s) {
        auto itr = kegs.rbegin();

        ll largest = itr->first;
        ll count = itr->second;
        
        itr++;
        ll next_largest = itr->first;
        
        // pour levers 
        ll diff = largest - next_largest;
        volume += diff*count
        
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
    
    solution(n, m, arr);
    
    return 0;
}

