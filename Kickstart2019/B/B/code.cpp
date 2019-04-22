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

int main() {
    
    IOS;
    ll t;
    cin >> t;
    for(int test=0; test<t; test++) {

        ll n;
        cin >> n;
        vector<int> s; s.resize(n);
        vector<int> e; e.resize(n);
        vector<int> l; l.resize(n);
        for(int i=0; i<n; i++) {
            cin >> s[i];
            cin >> e[i];
            cin >> l[i];
        }
       
        ll energyf = 0;

        int eating_time = 0;
        vector<pair<int, int>> ce;
        unordered_set<int> unused; for(int i=0; i<n; i++) {unused.emplace(i);}
        for(int i=0; i<n; i++) {
            
            ce.clear();
            for(auto x : unused) 
                ce.push_back({max(e[x] - eating_time*l[x], 0), x});
            auto best = *max_element(ce.begin(), ce.end());
            
            energyf += best.first;
            unused.erase(best.second);
            eating_time = s[best.second];
        
        }

        ll energyb = 0;
        eating_time = n*s[0] - s[0];
        for(int i=0; i<n; i++) {unused.emplace(i);}
        for(int i=0; i<n; i++) {
            
            ce.clear();
            for(auto x : unused) 
                ce.push_back({max(e[x] - eating_time*l[x], 0), x});
            auto best = *max_element(ce.begin(), ce.end());
            if(best.first == 0) {
            

            }

//            printf("vec: ");
//            for(auto x : ce) 
//                printf("(%d, %d), ", x.first, x.second);
//            printf("best: (%d, %d)\n", best.first, best.second);

            energyb += best.first;
            unused.erase(best.second);
            eating_time -= s[best.second];
            
        }

        printf("Case #%d: %lld\n", test+1, max(energyf, energyb));
    }

    return 0;
}

