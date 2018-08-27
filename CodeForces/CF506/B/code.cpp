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

    ll best = 1;
    for(ll i=0; i<n-1; i++) {
        ll j = i;
        while(j < n-1 and a[j+1] <= a[j]*2) 
            j++;
        best = max(j - i + 1, best);
        i = j;
    }
    printf("%lld\n", best);
}



int main() {

    // variables
    ll n;
    cin >> n;

    vector<ll> arr; arr.resize(n);
    for(ll i=0; i<n; i++) {
        scanf("%lld", &arr[i]);
    }
    
    solution(n, arr);
    
    return 0;
}

