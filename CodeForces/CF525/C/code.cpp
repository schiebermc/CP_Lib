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


ll get_needed_addition(ll val1, ll val2, ll mod_val) {
    // return n, where
    // (val1 + n) % mod_val = val2
    ll x = val1 % mod_val;
    if(x == val2)
        return 0;
    if(x < val2) 
        return val2 - x;
    else
        return (mod_val - x) + val2;

}

int main() {

    // variables
    ll n;
    cin >> n;

    vector<ll> a; a.resize(n);
    for(ll i=0; i<n; i++) {
        scanf("%lld", &a[i]);
    }

    //printf("%lld\n", n+1);
    //printf("1 %lld %lld\n", n, n);
    ll first_val = a[n-1] + n;
    ll last_val = first_val;

    ll mod_val = first_val + 1;
    ll added = 0;
    
    vector<vector<ll>> adds;
    adds.push_back({ll(1), n, n});
    for(ll i=n-2, count=1; i>= 0; i--, count++) {
        ll add_val = get_needed_addition(a[i] + added, first_val-count, mod_val);
        added += add_val;
        //printf("1 %lld %lld\n", add_val, i+1);

        if(add_val != 0)
            adds.push_back({ll(1), i+ll(1), add_val});
    }

    adds.push_back({ll(2), n, mod_val});
    //printf("2 %lld %lld\n", mod_val, n); 
    
    printf("%zu\n", adds.size());
    for(auto x : adds)
        printf("%lld %lld %lld\n", x[0], x[1], x[2]);

    return 0;
}

