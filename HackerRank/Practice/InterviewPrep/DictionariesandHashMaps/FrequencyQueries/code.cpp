//#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <climits>

using namespace std;

typedef long long int ll;

int main() {

    // variables
    ll n;
    cin >> n;

    // need two maps
    ll q_type, val, freq1, freq2;
    unordered_map<ll, ll> stuffs;
    unordered_map<ll, unordered_set<ll>> counts;
    for(ll i=0; i<n; i++) {

        scanf("%lld %lld", &q_type, &val);
        if(q_type == 1) {

            if(stuffs.find(val) == stuffs.end()) {
                stuffs[val] = 1;
            } else {
                freq1 = stuffs[val];
                counts[freq1].erase(val);
                stuffs[val] += 1;
            }
            
        } else if (q_type == 2) {

            if(stuffs.find(val) == stuffs.end()) {
                continue;
            } else {
                freq1 = stuffs[val];
                counts[freq1].erase(val);
                stuffs[val] -= 1;
                if(stuffs[val] == 0){
                    stuffs.erase(val);
                    continue;
                }
            }

        } else {

            if(counts.find(val) != counts.end() and counts[val].size() != 0)
                printf("1\n");
            else
                printf("0\n");

        }
        
        if(q_type == 1 or q_type == 2) {
            freq2 = stuffs[val];
            if(counts.find(freq2) == counts.end())
                counts[freq2] = {val};
            else
                counts[freq2].emplace(val);
        }

    }
    
    return 0;
}

