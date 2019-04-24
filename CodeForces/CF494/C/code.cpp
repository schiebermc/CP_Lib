//#include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

typedef long long int ll;


void solution(ll n, ll k, vector<ll> a){

    float best = 0;
    for(ll i=k; i<=n; i++) {
        ll summ = 0;
        for(ll j=0; j<i; j++) {
            summ += a[j];
        }
        float val = (float)summ / (float)i;
        best = (best < val ? val : best);
        for(ll j=i; j<n; j++){
            summ -= a[j-i];
            summ += a[j];
            float val = (float)summ / (float)i;
            best = (best < val ? val : best);
        }        
    }
    printf("%f\n", best);
}


int main() {

    // variables
    ll n, k;
    cin >> n >> k;

    vector<ll> arr; arr.resize(n);
    for(ll i=0; i<n; i++) {
        scanf("%lld", &arr[i]);
    }
    
    //validation()
    solution(n, k, arr);
    
    return 0;
}

