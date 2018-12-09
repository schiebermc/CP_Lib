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

void solution(ll n, ll m){

    ll j, k, x;
    vector<ll> a(n);
    for(ll i=0; i<m; i++) {
        cin >> j >> k >> x;
        j -= 1;
        k -= 1;
        a[j] += x;
        if(k+1 < n){
            a[k+1] -= x;
        }
    }       
    ll current = 0;
    ll best = 0;
    for(ll i=0; i<n; i++) {
        current += a[i];
        best = (best < current ? current : best);
    }
    printf("%lld\n", best);

}

int main() {

    // variables
    ll n, m;
    cin >> n >> m;
    solution(n, m);
    
    return 0;
}

