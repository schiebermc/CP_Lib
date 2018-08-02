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

    ll count1 = 0, count2 = 0;
//    for(ll i=0; i<n; i++) {
//        count2 = 0;
//        for(ll j=i+1; j<n; j++) {
//            if(a[j] < a[i]) {
//                count1++;
//                count2++;
//            }
//            if(count2 > 2 ) {
//                printf("Too chaotic\n");
//                return;
//            }
//        }
//    }

    map<ll, set<ll>> 
    printf("%lld\n", count1);
}

int main() {

    // variables
    ll t, n;
    cin >> t;
    
    for(ll i=0; i<t; i++) {
        cin >> n;
        vector<ll> a; a.resize(n);
        for(ll j=0; j<n; j++) {
            scanf("%lld ", &a[j]);
        }   
        solution(n, a);

    }
    
    return 0;
}

