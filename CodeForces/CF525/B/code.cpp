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
    ll n, k;
    cin >> n >> k;

    ll val;
    set<ll> arr;;
    for(ll i=0; i<n; i++) {
        scanf("%lld", &val);
        arr.emplace(val);
    }

    ll subtracted = 0;
    for(ll i=0; i<k; i++) {

        if(arr.size() == 0) {
            printf("0\n");
        } else {
            
            auto itr = arr.begin();
            val = *itr;
            printf("%lld\n", val - subtracted);
            subtracted += (val - subtracted);
            arr.erase(val); 
        }                        

    }
    
    
    return 0;
}

