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
    ll n, k;
    cin >> n >> k;

    // add check for n not within ll
    if(n*2 < k) {
        printf("0\n");
        return 0;
    }

    if(n < k) {
        ll bot = k - n;
        printf("%lld\n", (n - bot + 1) / 2);   
    } else {
        printf("%lld\n", k / 2);
    }
    
    return 0;
}

