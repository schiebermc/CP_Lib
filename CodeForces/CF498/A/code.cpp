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


void solution(ll n, vector<ll> a){

    for(ll i=0; i<n; i++) {
        if(a[i] % 2 == 1) {
            printf("%lld ", a[i]);
        } else {
            printf("%lld ", a[i]-1);
        }
    }
    printf("\n");
}

int main() {

    // variables
    ll n;
    cin >> n;

    vector<ll> arr; arr.resize(n);
    for(ll i=0; i<n; i++) {
        scanf("%lld", &arr[i]);
    }
    
    //validation(0, 10, 10)
    solution(n, arr);
    
    return 0;
}

