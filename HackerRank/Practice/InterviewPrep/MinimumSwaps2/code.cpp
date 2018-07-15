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

void swap(ll i, ll j, vector<ll>& a); 

void solution(ll n, vector<ll> a){
    
    ll count = 0;
    for(ll i=0; i<n; i++) {
        if(a[i] != i+1){
            swap(a[i]-1, i, a);
            count++;
            i--;
        }
    }
    printf("%lld\n", count);
}

void swap(ll i, ll j, vector<ll>& a) {
    ll tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
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

