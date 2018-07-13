//#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>

using namespace std;

typedef long long int ll;

void get_counts(ll &rows, ll &cols, vector<vector<ll>> &grid);

void solution(ll n, vector<ll> a){

    map <ll, ll> distances;
    for(auto x : a) {
        if(distances.count(x) == 0)
            distances[x] = 1;
        else
            distances[x] += 1;
    }

    vector<vector<ll>> grid;
    if(distances.count(0) == 0){
        printf("-1\n");
        return;
    } else {

        ll last = 0;
        ll rows, cols;
        vector<ll> stops = {0, 0, 0, 0};

        for (auto& kv : distances) {
            if(kv.first - last > 1) { // ensures not skips by two
                printf("-1\n");
                return;
            }
            if(kv.first*4 < kv.second) { // ensures does not exceed max
                printf("-1\n");
                return;
            }
        

            ll expansion = kv.first*4-4;

            last = kv.first;
        }
    }
}

void get_counts(ll &rows, ll &cols, vector<vector<ll>> &grid) {
    rows = grid.size();
    cols = grid[0].size();
}


int main() {

    // variables
    ll n;
    cin >> n;

    vector<ll> arr; arr.resize(n);
    for(ll i=0; i<n; i++) {
        scanf("%lld", &arr[i]);
    }
    
    //validation()
    solution(n, arr);
    
    return 0;
}

