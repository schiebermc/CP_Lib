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


int main() {

    // variables
    ll n;
    cin >> n;
    n++;
    vector<ll> prevs = {0, 1};

    ll val;
    for(ll i=0; i<n-2; i++) {
    
        val = prevs[0] + prevs[1];
        swap(prevs[0], prevs[1]);
        swap(prevs[1], val);

    }
    
    if(n == 1)
        printf("%lld\n", prevs[0]);  

    else
        printf("%lld\n", prevs[1]);     
    


    return 0;
}

