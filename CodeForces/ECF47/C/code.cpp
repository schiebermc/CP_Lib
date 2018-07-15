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

float average(vector<ll> s);
void change(vector<ll>& s, ll i, ll d, ll x);

void solution(ll n, ll m){

    ll xt = 0;
    ll dl = 0;
    ll dh = 0;
    vector<ll> s; s.resize(n);
    for(ll i=0; i<m; i++) {
        ll x, d;
        scanf("%lld %lld", &x, &d);
        if(d < 0 ) {
            dl += d;   
        } else {
            dh += d;
        }
        xt += x;
    }
    
    change(s, 0, dh, 0);        
    change(s, n/2, dl, xt);        
    printf("%f\n", average(s));
}

void change(vector<ll>& s, ll i, ll d, ll x){
    for (ll k=0; k<s.size(); k++) {
        s[k] += (x + d*abs(i-k));
    }
}


float average(vector<ll> s) {
    ll summ = 0;
    for(auto x : s) {
        summ += x;
    }
    return (float)summ / s.size();

}

int main() {

    // variables
    ll n, m;
    cin >> n >> m;
    
    //validation(0, 10, 10)
    solution(n, m);
    
    return 0;
}

