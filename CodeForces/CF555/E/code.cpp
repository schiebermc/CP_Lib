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
    ll n;
    cin >> n;

    vector<ll> a; a.resize(n);
    for(ll i=0; i<n; i++) {
        cin >> a[i];
    }
    
    map<ll, ll> b;
    for(ll i=0; i<n; i++) {
        ll num;
        cin >> num;
        if(b.find(num) == b.end())
            b[num] = 1;
        else
            b[num]++;
    }

    for(ll i=0; i<n; i++) {
        ll best = n - a[i];
        auto c = b.lower_bound(best);
        if(c == b.end())
            c = b.begin();
        cout << (a[i] + c->first)%n << " ";    
        c->second--;
        if(c->second == 0)
            b.erase(c);
    } 
    cout << endl;

    return 0;
}

