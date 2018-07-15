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


void solution(ll n, ll m, vector<ll> games, vector<ll> wallet){

    ll count = 0;
    ll indw = 0;
    for (auto x : games) {
        if(wallet[indw] >= x) {
            count++;
            indw++;
        }
        if(indw == wallet.size()){
            break;
        }
    }
    printf("%lld\n", count);
}

int main() {

    // variables
    ll n, m;
    cin >> n >> m;

    vector<ll> games; games.resize(n);
    for(ll i=0; i<n; i++) {
        scanf("%lld", &games[i]);
    }
    vector<ll> wallet; wallet.resize(m);
    for(ll i=0; i<n; i++) {
        scanf("%lld", &wallet[i]);
    }
    
    //validation(0, 10, 10)
    solution(n, m, games, wallet);
    
    return 0;
}

