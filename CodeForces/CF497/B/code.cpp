//#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>


using namespace std;

typedef long long int ll;


void solution(ll n){

    ll w, h;
    bool good = true;
    ll peak;
    ll nexth;
    ll nextl;
    for(ll i=0; i<n; i++) {
        scanf("%lld %lld", &w, &h);
        if(i==0) {
            peak = max(w, h);
        } else {  
            nexth = max(w, h);
            nextl = min(w, h);
            if(nexth <= peak) {
                peak = nexth;
            } else if(nextl <= peak) {
                peak = nextl;
            } else {
                good = false;
                break;
            }
        }      
    }

    if(good)
        printf("YES\n");
    else
        printf("NO\n");

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
    ll n;
    cin >> n;
    
    //validation(0, 10, 10)
    solution(n);
    
    return 0;
}

