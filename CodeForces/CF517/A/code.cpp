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

ll cells_for_ring(ll w, ll h) {
    return w*2 + (h-2)*2;
}

void solution(ll w, ll h, ll k){

    ll tots = 0;
    for (ll i=0; i<k; i++) {
        ll diff = i*4;
        tots += cells_for_ring(w - diff, h - diff);
    }
    printf("%lld\n", tots);

}


int main() {

    // variables
    ll n, m, k;
    cin >> n >> m >> k;

    //validation(0, 10, 10)
    solution(n, m, k);
    
    return 0;
}

