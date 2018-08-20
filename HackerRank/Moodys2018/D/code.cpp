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

ll counter (ll a, ll m, ll largest); // start largest out as a+1

void solution(ll a, ll m) {
    ll count = counter(m, a, a+1); 
    printf("%lld\n", count);
}

ll counter (ll a, ll m, ll largest) // start largest out as a+1
{
    //printf("a: %lld, m: %lld\n", a, m);
    // the next lender must do min(a, x - 1)
    if(m < 0 or a < 0)
        return 0;
    
    if(m == 0)
        return 1;

    ll count = 0;
    for(ll i=largest-1; i>=1; i--) {
        count += counter(a-1, m-i, i);
    }
    return count;
}

int main() {

    // variables
    ll q, a, m, count;
    cin >> q;

    for(ll i=0; i<q; i++) {
        cin >> a >> m;
        solution(a, m); 
    }   
    
    return 0;
}

