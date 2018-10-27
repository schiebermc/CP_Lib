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


void solution(ll n, ll k, vector<ll> a){

    
    set<ll> largers;
    for(ll i=0; i<n; i++) {    
        if(a[i] > k) {
            largers.emplace(i);
        }
    }

    bool first = true;
    ll best = 0;
    auto itr = largers.begin();
    while(true) {
        
        ll left = *itr;
        while(next(itr) != largers.end() and a[*next(itr)] == a[left])
            itr++;
    
        ll right;   
        if(next(itr) == largers.end())
            right = n;
        else
            right = *next(itr);

        ll length;
        if(first){
            length = right;
            first = false;
        } else {
            length = right - left;
        }        

        if(length > best)
            best = length; 
        
        if(next(itr) == largers.end())
            break;
        
        itr++;
    }   
    printf("%lld\n", best);
 
}

int main() {

    // variables
    ll t;
    cin >> t;
    
    for(ll i=0; i<t; i++) {

        ll n, k;
        cin >> n >> k;
        vector<ll> arr; arr.resize(n);
        for(ll i=0; i<n; i++) {
            scanf("%lld", &arr[i]);
        }

        solution(n, k, arr);

    }

    
    
    return 0;
}

