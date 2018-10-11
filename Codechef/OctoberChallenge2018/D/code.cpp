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

void print_vector(vector<ll>& a);

void solution(ll n, ll m, vector<ll> a, vector<ll> b){

    print_vector(a);
    print_vector(b);

}

void print_vector(vector<ll>& a) {
    for(auto x : a)
        printf("%lld ", x);
    printf("\n");

}

int main() {

    // variables
    ll n, m;
    cin >> n >> m;

    vector<ll> a; a.resize(n);
    for(ll i=0; i<n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<ll> b; b.resize(n);
    for(ll i=0; i<n; i++) {
        scanf("%lld", &b[i]);
    }
    
    //validation(0, 10, 10)
    solution(n, m, a, b);
    
    return 0;
}

