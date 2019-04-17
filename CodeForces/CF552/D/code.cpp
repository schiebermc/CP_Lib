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

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long int ll;

ll brute_force(ll n, ll max_b, ll max_a, vector<ll>& s) {

    ll N = pow(2, n);
    ll dist = 0;
    
    return 0;
}

ll solution1(ll n, ll max_b, ll max_a, vector<ll>& s) {

    ll dist = 0;
    ll a = max_a;
    ll b = max_b;
    for(ll i=0; i<n; i++, dist++) {

//        printf("before: %lld, %lld\n", a, b);    
        if(a == 0 and b == 0)
            break;
        
        if(b != 0) {
            if(a == max_a){
                a--;
            }
            else if(a == 0) {
                b--;
                a+=s[i];
            }
            else if(s[i] == 1) {
                b--;
                a++;
            } 
            else {
                a--;
            }
        }
        
        else {
            a--;
        }
        
//        printf("after: %lld, %lld\n\n", a, b);    
    }
    return dist;
}

void validation(ll start_seed, ll end_seed, ll n) {

    for(ll s=start_seed; s<=end_seed; s++) {
        srand(s);
        vector<ll> S;
        for(ll i=0; i<n; i++) {
            S.push_back(rand()%2);
        }
        for (auto x : S) {
            printf("%lld, ", x);
        }
        printf("\n");
        ll max_a = rand()%4+1;
        ll max_b = rand()%4+1;
        auto val1 = brute_force(n, max_b, max_a, S);
        auto val2 = solution1(n, max_b, max_a, S);
        if(val1 != val2) {
            printf("failed at seed: %lld\n", s);
        }

    }

}

int main() {

    IOS;
    ll n, max_b, max_a;
    cin >> n >> max_b >> max_a;

    vector<ll> s; s.resize(n);
    for(ll i=0; i<n; i++) {
        cin >> s[i];
    }
    
    //validation(0, 10, 8);
    printf("%lld\n", solution1(n, max_b, max_a, s));

    return 0;
}

