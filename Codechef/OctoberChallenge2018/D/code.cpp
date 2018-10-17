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

void print_vector(vector<ll>& a);

void solution(ll n, ll m, vector<ll> a, vector<ll> b){

    // strategy
    // 1. use a min heap, each element is a day. save
    // the index of the day as the second element to access b[ind]
    // 2. continuously decrement the most expensive day using the balloons
    // that we have. push the new day back on the heap when accounted for.
    
    ll total = 0;
    map<ll, vector<ll>> days;
    for (ll i=0; i<n; i++){
        
        ll cost = -1*a[i]*b[i];
        if(days.find(cost) == days.end()) 
            days[cost] = {i};
        else 
            days[cost].push_back(i);
        
        total += a[i];
    }    
    
    if(total < m) {
        printf("%lld\n", (ll)0);
        return;
    }

    while(m != 0){
        auto day = days.begin();
        
        ll cost = day->first;
        ll ind = day->second[0];
        ll new_cost = cost + b[ind];
        
        if(cost > 0) // we had more than enough baloons, gtfo
            break;

        if(days.find(new_cost) == days.end())
            days[new_cost] = vector<ll>({ind});
        else 
            days[new_cost].push_back(ind);

        if(day->second.size() == 1)
            days.erase(day);
        else
            day->second.erase(day->second.begin());;

        m --; 
    }

    auto day = days.begin();
    ll cost = day->first;
    printf("%lld\n", max((ll)0, -1*cost));           

}

void print_vector(vector<ll>& a) {
    for(auto x : a)
        printf("%lld ", x);
    printf("\n");

}

int main() {

    // variables
    ll n, m;
    cin >> n >> m;

    vector<ll> a; a.resize(n);
    for(ll i=0; i<n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<ll> b; b.resize(n);
    for(ll i=0; i<n; i++) {
        scanf("%lld", &b[i]);
    }
    
    //validation(0, 10, 10)
    solution(n, m, a, b);
    
    return 0;
}

