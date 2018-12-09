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
    ll n, m;
    cin >> n >> m;

    ll r;
    for(ll i=0; i<n; i++) {
        scanf("%lld", &r);
        if(r < m)
            printf("Bad boi\n");
        else
            printf("Good boi\n");
    }
    
    return 0;
}

