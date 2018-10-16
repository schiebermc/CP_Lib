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

ll furthest_truth(ll n, ll i, ll j, vector<ll>& a) {
    // INCLUSIVE
    ll truth = -1;
    for(ll k=i; k<=j; k++) {
        if(a[k] == 1)
            truth = k;
    }
    return truth;
}

void solution(ll n, ll r, vector<ll>& a){
    
    ll fh = furthest_truth(n, 0, 0+r-1, a);
    if(fh == -1){
        printf("-1\n");
        return;
    }

    ll count = 1;
    for(ll i = fh; i+r<n; count++) {
        
        // furthest heater in this range
        ll j1 = furthest_truth(n, i+1, min(i+r-1, n-1), a);
        
        // furthest heater with range that won't break the heat
        ll j2 = furthest_truth(n, i+r, min(i+r+r-1, n-1), a);

        // assign whichever is further
        if(j2 != -1) {
            i = j2;
        } else {
            if(j1 == -1) {
                if(min(i+r-1, n-1) == n-1) {
                    break;
                } else {
                    printf("-1\n");
                    return;
                }
            } else {
                i = j1;
            }
        }
    
    }

    printf("%lld\n", count);

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

