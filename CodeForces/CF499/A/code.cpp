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


void solution(ll n, ll k, string s){

    vector<ll> weights;
    for(auto x : s) {
        weights.push_back(x - 96);
    }
    sort(weights.begin(), weights.end());

    ll last = weights[0];
    ll count = 1;
    ll summ = weights[0];
    for(ll i=1; i<weights.size(); i++) {
        if(count == k)
            break;
        if(last + 1 < weights[i]) {
            count++;
            summ += weights[i];
            last = weights[i];
        }
    }
    if(count == k) {
        printf("%lld\n", summ);
    } else {
        printf("-1\n");
    }

}

int main() {

    // variables
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    
    solution(n, m, s);
    
    return 0;
}

