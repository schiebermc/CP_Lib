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

void solution(ll n, vector<ll> a){

    map<ll, ll> stuff;

    // init the first two.
    if(n >= 1) 
        stuff[0] = a[0];
    if(n >= 2)
        stuff[1] = a[1];

    // get a starting point
    ll best;
    if(n >= 2)
        best = max(stuff[0], stuff[1]);
    else
        best = stuff[0];

    // O(N)
    for(ll i=2; i<n; i++) { // get the best sum up to this point
        ll tmp = LONG_MIN;
        for(ll j=i-3; j<=i-2; j++) { // check only the back two
             if(j < 0)
                continue;
             if(stuff[j] > tmp)
                tmp = stuff[j];    
        }
        stuff[i] = max(a[i], a[i] + tmp); // apply the best 
        stuff[i] = max(stuff[i], tmp);
        best = max(best, stuff[i]);
    }

    printf("%lld\n", best);
}

int main() {

    // variables
    ll n;
    cin >> n;

    vector<ll> arr; arr.resize(n);
    for(ll i=0; i<n; i++) {
        scanf("%lld", &arr[i]);
    }
    
    //validation(0, 10, 10)
    solution(n, arr);
    
    return 0;
}

