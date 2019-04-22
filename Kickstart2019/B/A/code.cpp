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
    ll t;
    cin >> t;
    for(int test=0; test<t; test++) {

        ll n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        int goods = 0;
        for(ll question=0; question<q; question++) {

            ll l, r;
            cin >> l >> r;
            unordered_map<char, int> c;
            for(ll ind=l; ind<=r; ind++) {
                auto x = s[ind-1];
                if(c.find(x) == c.end())
                    c[x] = 1;
                else
                    c[x]++;
            }
            
            bool one_odd = false;
            bool pos = true;
            for(auto kv : c) {
                if(kv.second%2 == 1) {
                    if(one_odd) {
                        pos = false;
                        break;
                    } else {
                        one_odd = true;
                    }
                }
            }
            if(pos)
                goods++;
        }
        
        printf("Case #%d: %d\n", test+1, goods);

    } 

    return 0;
}

