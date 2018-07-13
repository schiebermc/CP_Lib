//#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

typedef long long int ll;


void solution(ll n, ll d, vector<ll> a){

    ll count = 2;
    for (ll i=0; i<n-1; i++) {
        ll val = (a[i+1] - a[i] + 1 - 2*d);
        val = (val > 2 ? 2 : val);
        count += (val > 0 ? val : 0);
        //printf("%lld\n", val);
    }
    printf("%lld\n", count);
    return;
}

int main() {

    // variables
    ll n, d;
    cin >> n >> d;

    vector<ll> arr; arr.resize(n);
    for(ll i=0; i<n; i++) {
        scanf("%lld", &arr[i]);
    }
    
    //validation()
    solution(n, d, arr);
    
    return 0;
}

