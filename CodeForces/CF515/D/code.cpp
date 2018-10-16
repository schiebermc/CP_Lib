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


void solution(ll n, ll m, ll k, vector<ll> a){

    ll best = 0;
    for(ll i=0; i<n; i++) {

        ll boxes = 0;
        ll objects = 0;
        ll csumm = 0;

        for(ll j=i; j<n; j++) {

            if(a[j] + csumm <= k) {
                csumm += a[j];
                objects++;
            } else {
                boxes++;
                csumm = 0;
                j--;
            }

            if(boxes == m) {
                break;
            }

            if(j == n-1) {
                printf("%lld\n", objects);
                return;
            }
        }
        //printf("%lld, %lld\n", objects, i);
        if(objects > best)
            best = objects;
    }
    printf("%lld\n", best);

}

int main() {

    // variables
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> arr; arr.resize(n);
    for(ll i=0; i<n; i++) {
        scanf("%lld", &arr[i]);
    }
    
    //validation(0, 10, 10)
    solution(n, m, k, arr);
    
    return 0;
}

