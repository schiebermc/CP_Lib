`//#include <bits/stdc++.h>

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


void solution(ll n, ll m, vector<ll> a){


}

void solution2(ll n, ll m, vector<ll> a){


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
        //if(solution2(n, a) != solution(n, a)) {
        //    printf("failed at seed: %lld\n", s);
        //}

    }

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

