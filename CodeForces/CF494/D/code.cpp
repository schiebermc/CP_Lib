//#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>

using namespace std;

typedef long long int ll;

ll get_min_number(map<ll, ll>d, ll b, vector<ll> a);

void solution(ll n, ll q, vector<ll> arr){

    map<ll, ll> d;
    for( auto x : arr) {
        if(d.count(x)) {
            d[x] += 1;
        } else {
            d[x] = 1;
        }

    }
    
    vector<ll> a;
    for (auto& kv : d ){
        a.push_back(kv.first);
    }
    std::sort(a.begin(), a.end(), greater<ll>());
    
    ll b;
    for(ll i=0; i<q; i++) {
        scanf("%lld", &b);
        printf("%lld\n", get_min_number(d, b, a));
    }
}

ll get_min_number(map<ll, ll>d, ll b, vector<ll> a){
    ll count = 0;
    ll coins = 0;
    for (auto val : a) {
        if(count == b)
            break;
        
        ll c = (b - count) / val;
        coins += c;
        count += c * val;
    }

    if(count == b)
        return coins;
    else
        return -1;
}

int main() {

    // variables
    ll n, q;
    cin >> n >> q;

    vector<ll> arr; arr.resize(n);
    for(ll i=0; i<n; i++) {
        scanf("%lld", &arr[i]);
    }
    
    //validation()
    solution(n, q, arr);
    
    return 0;
}

