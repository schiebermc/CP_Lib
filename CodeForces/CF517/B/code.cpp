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

bool solve(ll ind, ll n, vector<ll>& a, vector<ll>& b, vector<ll>& t);

void solution(ll n, vector<ll> a, vector<ll> b){
    
    vector<ll> t; t.resize(n);
    bool pos = solve(0, n, a, b, t);
    if(pos) {
        printf("YES\n");
        for (auto x : t) 
            printf("%lld ", x);
        printf("\n");
    } else
        printf("NO\n");

}

bool solve(ll ind, ll n, vector<ll>& a, vector<ll>& b, vector<ll>& t) {

    // depth of tree, solved
    if(ind == n)
        return true;

    bool pos = false;
    if(ind == 0) {
        for(ll i=0; i<=3; i++) {
            t[ind] = i;
            pos = solve(ind + 1, n, a, b, t);
            if(pos)
                break;
        }
    } else {
        for(ll i=0; i<=3; i++) {
            if(((t[ind-1] | i) == a[ind-1]) and ((t[ind-1] & i) == b[ind-1])) {
                t[ind] = i;
                return solve(ind + 1, n, a, b, t);  
            } else {
                continue;
            }
        }
    }
    return pos;
}


int main() {

    // variables
    ll n;
    cin >> n;

    n--;
    vector<ll> a; a.resize(n);
    for(ll i=0; i<n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<ll> b; b.resize(n);
    for(ll i=0; i<n; i++) {
        scanf("%lld", &b[i]);
    }
    
    n++;
    solution(n, a, b);
    
    return 0;
}

