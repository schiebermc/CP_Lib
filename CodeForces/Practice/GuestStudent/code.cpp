//#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <bitset>

using namespace std;

typedef long long int ll;


void solution(ll k, vector<ll>& a){

    ll days = 0;
    for(auto &x : a)
        days += x;
    
    ll weeks = k / days;
    ll rem = k - weeks * days;
    
    if(rem == 0){
        weeks--;
        rem += days;
    }
    ll fast_rem = 7;
    for(ll start_day=0; start_day<7; start_day++) {

        ll final_days = 0;
        ll count = 0;
        for(ll i=start_day; i<start_day+7; i++) {

            if(count == rem)
                break;
            ll day = i % 7;
            count += a[day];
            final_days++;

        }
        fast_rem = min(fast_rem, final_days);

    } 

    printf("%lld\n", weeks * 7 + fast_rem);

}

int main() {

    // variables
    ll t, k, n = 7;
    cin >> t;
    
    vector<ll> arr; arr.resize(n);

    for(ll i=0; i<t; i++) {
    
        scanf("%lld", &k);
        for(ll j=0; j<n; j++) {
            scanf("%lld", &arr[j]);
        }
   
        //printf("i: %lld - ", i);
        //for(auto x : arr)
        //    printf(" %lld ", x);
        //printf("\n"); 
        solution(k, arr);

            
    }

    return 0;
}

