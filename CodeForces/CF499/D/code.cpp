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

void solution(ll m, ll n){
    
    ll ans;
    vector<bool> truth;
    for(ll i=0; i<n; i++){ 
        printf("1\n");
        fflush(stdout);
        scanf("%d", &ans);
        if(ans == 0)
            return;
        truth.push_back((ans == -1 ? true : false));
    } 

    ll upper = m;
    ll lower = 1;
    ll next = (upper + lower) / 2;
    for(ll i=0; i<60-n; i++) {
        bool t = (truth[i%n]);
        printf("%d\n", next);
        fflush(stdout);
        scanf("%d", &ans);
        if(ans == 0)
            return;
        if((ans == -1 and t) or (ans == 1 and !t)) { // distance is lower
            upper = next;
        } else { // distance is higher
            lower = next;
        }
        ll next = (upper + lower) / 2;
    }
}

int main() {

    // variables
    ll n, m;
    scanf("%d %d", &n, &m);

    solution(n, m);
    
    return 0;
}

