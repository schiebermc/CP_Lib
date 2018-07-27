//#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <set>

using namespace std;

typedef int ll;

void query(ll x, ll & ans);

void solution(ll m, ll n){
    
    ll ans;
    vector<bool> truth;
    for(ll i=0; i<n; i++){ 
        query(1, ans);
        truth.push_back((ans == 1 ? true : false));
    } 

    ll upper = m;
    ll lower = 2;
    ll next = (upper + lower) / 2;
    for(ll i=0; i<60-n; i++) {
        query(next, ans);
        if(!truth[i%n])
            ans *= -1;
        if(ans == -1) { // distance is lower
            upper = next - 1;
        } else { // distance is higher
            lower = next + 1;
        }
        next = (upper + lower) / 2;
    }
}

void query(ll x, ll &ans) {
    cout<<x<<"\n";
    fflush(stdout);
    cin>>ans;
    if(ans==0 || ans==-2)
        exit(0);
}

int main() {

    // variables
    ll n, m;
    scanf("%d %d", &n, &m);

    solution(n, m);
    
    return 0;
}

