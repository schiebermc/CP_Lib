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

    ll q, n, a, b, target, profit; 
    cin >> q;
   
    for(ll i=0; i<q; i++) {
        scanf("%lld", &n);
        target = 0;
        for(ll j=0; j<n; j++) {
            scanf("%lld %lld", &a, &b);     
            target = max(target + b - a, (ll)0);
        }      
        if(target > 0)
            printf("1\n");
        else
            printf("0\n");
    }

    return 0;
}

