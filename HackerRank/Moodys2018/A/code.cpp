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

int main() {

    // variables
    ll n;
    cin >> n;

    vector<ll> l; l.resize(n);
    vector<ll> h; h.resize(n);
    vector<ll> c; c.resize(n);
    for(ll i=0; i<n; i++) {
        scanf("%lld", &l[i]);
    }
    for(ll i=0; i<n; i++) {
        scanf("%lld", &h[i]);
    }
    for(ll i=0; i<n; i++) {
        scanf("%lld", &c[i]);
    }
   
    ll cgu = 0;
    ll cgd = 0;
    for(ll i=1; i<n; i++) {
        if(c[i-1] < l[i]) 
            cgu++;
        if(c[i-1] > h[i])
            cgd++;
    }   
    printf("%lld %lld\n", cgu, cgd);
 
    return 0;
}

