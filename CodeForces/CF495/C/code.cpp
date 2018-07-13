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


ll solution(ll n, vector<ll> a){
   
    map<ll, ll> d1; 
    map<ll, ll> d2; 

    // O(nlogn)
    ll count = ((n - 1) * (n)) / 2;
   
    ll flags = 0;
    map<ll, ll> flagged;
    for(ll i=0; i<n-1; i++){
        if(d1.count(a[i]) == 0){ 
            d1[a[i]] = i;
        } else {
            count -= (n-1-i); 
            flags += 1;
        }
        flagged[i] = flags;
    }
        
    for(ll i=0; i<n-1; i++){
        if(d2.count(a[n-1-i]) == 0) 
            d2[a[n-1-i]] = n-1-i;
        else {
            //printf("flagged; %lld\n", flagged[n-2-i]);
            count -= ((n-1-i) - flagged[n-2-i]);//(d2[a[n-1-i]] - (n-1-i)) * (n-1-i);
            //printf("%lld, %lld, %lld, -- %lld -- %lld\n", a[n-1-i], d2[a[n-1-i]], (n-1-i), (n - 1 - i) - flagged[n-1-i], flagged[n-1-i]);
        }
        //printf("%lld\n", count);
    }
    printf("%lld\n", count);
    return count;
}

ll solution2(ll n, vector<ll> a){
   
    map<ll, ll> d1; 
    map<ll, ll> d2; 

    // O(nlogn)
    
    for(ll i=0; i<n; i++){
        if(d1.count(a[i]) == 0) 
            d1[a[i]] = i;
        if(d2.count(a[n-1-i]) == 0) 
            d2[a[n-1-i]] = n-1-i;
    }

    // O(n^2)
    ll count = 0;
    for (auto& kv1 : d1) {
        for (auto& kv2 : d2) {
            if(kv1.second < kv2.second){
                count++;
                //printf("%lld, %lld\n", kv1.first, kv2.first);
            }
        }
    }
    printf("%lld\n", count);
    return count;
}

void validation(ll start_seed, ll end_seed, ll n) {

    for(ll s=start_seed; s<=end_seed; s++) {
        srand(s);
        vector<ll> a;
        for(ll i=0; i<n; i++) {
            a.push_back(rand()%16);
        }
        //for (auto x : a) {
        //    printf("%lld, ", x);
        //}
        //printf("\n");
        if(solution2(n, a) != solution(n, a)) {
            printf("failed at seed: %lld\n", s);
        }

    }

}
int main() {

    // variables
    ll n;
    cin >> n;

    vector<ll> arr; arr.resize(n);
    for(ll i=0; i<n; i++) {
        scanf("%lld", &arr[i]);
    }
    
    //validation(0, 100, 1000);
    solution(n, arr);
    
    return 0;
}

