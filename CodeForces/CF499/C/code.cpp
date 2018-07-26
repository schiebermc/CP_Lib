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


void solution(ll n, ll m, vector<ll> a, vector<ll> b){

    // fuel is only decreasing. and it needs to end with 0 to be minimal
    
    double x;
    double summ = 0.0;
    for(ll i=n-1; i>=0; i--) {
        x = (m + (summ)) / (a[i] - 1);
        summ += x;   
        x = (m + (summ)) / (b[i] - 1);
        summ += x;   
    }

    if(isinf(summ))
        printf("-1\n");
    else
        printf("%f\n", summ);

}

int main() {

    // variables
    ll n, m;
    cin >> n;
    cin >> m;

    vector<ll> arr1; arr1.resize(n);
    for(ll i=0; i<n; i++) {
        scanf("%lld", &arr1[i]);
    }
    vector<ll> arr2; arr2.resize(n);
    for(ll i=0; i<n; i++) {
        scanf("%lld", &arr2[i]);
    }
    
    //validation(0, 10, 10)
    solution(n, m, arr1, arr2);
    
    return 0;
}

