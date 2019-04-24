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

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long int ll;

int main() {

    IOS;
    ll n, m;
    cin >> n >> m;

    ll ec = 0, oc = 0, ek = 0, ok = 0, a;
    for(ll i=0; i<n; i++) {
        cin >> a;
        if(a%2 == 0)
            ec++;
        else
            oc++;
    }
    for(ll i=0; i<m; i++) {
        cin >> a;
        if(a%2 == 0)
            ek++;
        else
            ok++;
    }

    printf("%lld\n", min(ec, ok) + min(oc, ek));

    return 0;
}

