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

bool check_color(ll i, ll j, ll n, ll color, vector<vector<ll>> a);

bool solution(ll n, vector<vector<ll>> a){

    bool good = true;
    for(ll i=0; i<n; i++) {
        for(ll j=0; j<n; j++) {
            good = good and check_color(i-1, j, n, a[i][j], a);
            good = good and check_color(i+1, j, n, a[i][j], a);
            good = good and check_color(i, j-1, n, a[i][j], a);
            good = good and check_color(i, j+1, n, a[i][j], a);
        }
    }
    return good;
}

bool check_color(ll i, ll j, ll n, ll color, vector<vector<ll>> a) {

    if(i < n and i >= 0 and j < n and j >= 0) 
        return !(color == a[i][j]);
    else
        return true;
}

int main() {

    // variables
    ll t;
    cin >> t;

    for(ll i=0; i<t; i++) {
        ll n;
        cin >> n;
        vector<vector<ll>> arr; arr.resize(n);
        for(ll j=0; j<n; j++) {
            arr[j].resize(n);
            for(ll k=0; k<n; k++) {
                scanf("%lld", &arr[j][k]);
            }
        }
        
        bool result = solution(n, arr);
        (result ? printf("Yes\n") : printf("No\n"));
    }    

    return 0;
}

