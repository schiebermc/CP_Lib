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

ll gcd(ll a, ll b){
    while (b) {
        ll tmp_a = a;
        a = b;
        b = tmp_a%b;
    }
    return a;
}

int main() {

    IOS;
    ll a, b;
    cin >> a >> b;

    auto g = gcd(a, b);
    ll best = a*b / g;
    ll ans = 0;
    for(ll i=0; i<100; i++) {
        ll val = (a*b + a*i + b*i + i*i) / (g + i);
        printf("%lld, %lld, %lld, %lld\n", i, val, a+i, b+i);
        if(val < best) {
            ans = i;
        } 
    }   

    printf("%lld\n", ans);
    
    return 0;
}

