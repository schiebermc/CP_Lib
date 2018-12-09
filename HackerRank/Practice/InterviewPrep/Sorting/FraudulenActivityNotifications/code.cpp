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


void solution(ll n, ll d, vector<ll> a){

    float median;
    ll count = 0;
    set<ll> trailing_days;
    for(ll i=0; i< d; i++) {

        if(i<d)
            trailing_days.emplace(a[i]);

        


        ll val = a[i-d];
        

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

