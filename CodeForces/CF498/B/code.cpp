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


void solution(ll n, ll k, vector<ll> a){

    ll summ = 0;
    vector<ll> b = a;
    map<ll, ll> stuff;
    sort(a.begin(), a.end());
    for(ll i=0; i<k; i++) {
        summ += a[n-1-i];
        if(stuff.count(a[n-1-i]) != 0 ) {
            stuff[a[n-1-i]] += 1;
        } else {
            stuff[a[n-1-i]] = 1;
        }
    }
  
    ll count = 0;
    vector<ll> counts;
    for(ll i=0; i<n; i++) {
        count++;
        if(stuff.count(b[i]) != 0 and stuff[b[i]] != 0) {
            stuff[b[i]] -= 1;
            counts.push_back(count);
            count = 0;
        }
    }
    
    counts[k-1] += count;
    printf("%lld\n", summ); 
    for(ll i=0; i<k; i++) {
        printf("%lld ", counts[i]);
    }
    printf("\n");

}


int main() {

    // variables
    ll n, m;
    cin >> n >> m;

    vector<ll> arr; arr.resize(n);
    for(ll i=0; i<n; i++) {
        scanf("%lld", &arr[i]);
    }
    
    //validation(0, 10, 10)
    solution(n, m, arr);
    
    return 0;
}

