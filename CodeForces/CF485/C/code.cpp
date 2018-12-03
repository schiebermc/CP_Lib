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

int main() {

    // variables
    ll n;
    cin >> n;

    vector<ll> s; s.resize(n);
    vector<ll> c; c.resize(n);
    for(ll i=0; i<n; i++) {
        scanf("%lld", &s[i]);
    }
    for(ll i=0; i<n; i++) {
        scanf("%lld", &c[i]);
    }
   
    map<ll, float> cost;
    bool found = false;
    float val1, val2;
    ll best = LLONG_MAX;

    for(ll i=0 ;i<n; i++) {
        for(ll j=i+1; j<n; j++) {
            if(s[i] < s[j]) {
                val1 = float(c[i]) + float(c[j]) / 2.;
                val2 = float(c[j]) + float(c[i]) / 2.;
                if(cost.find(j) != cost.end())
                    cost[j] = min(val1, cost[j]);
                else
                    cost[j] = val1;
                if(cost.find(i) != cost.end()){
                    best = min(best, ll(val2 + cost[i]));
                    found = true;
                }
            }
        }
    }
     
    if(found){ 
        printf("%lld\n", best);
    } else {
        printf("-1\n");
    }
    return 0;
}

