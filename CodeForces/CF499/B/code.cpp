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


void solution(ll n, ll m, vector<ll> a){

    vector<ll> food(100, 0);
    for(auto x : a){
        food[x-1] += 1;
    }

    sort(food.begin(), food.end());
  
    vector<float> best; 
    vector<ll> counts(n, 0);
    for(ll i=food.size()-1; i>=0 and i>=food.size()-n; i--) {
        best.push_back(food[i]);
    }

    //for(auto x : best) 
    //    printf("%f, ", x);
    //printf("\n"); 
    
    ll most;
    ll count = 0;
    while(count < n) {
        ll t = 0;
        ll j = 0;
        for(ll i=0; i<best.size(); i++) {
            if((best[i] / (counts[i]+1)) > t) {
                t = (best[i] / (counts[i]+1));
                j = i;
            }
        }
        
        counts[j]++;
        most = best[j] / counts[j];
        count++;
    }   
 
    printf("%lld\n", most);
}

int main() {

    // variables
    ll n, m;
    cin >> n >> m;

    vector<ll> arr; arr.resize(m);
    for(ll i=0; i<m; i++) {
        scanf("%lld", &arr[i]);
    }
    
    //validation(0, 10, 10)
    solution(n, m, arr);
    
    return 0;
}

