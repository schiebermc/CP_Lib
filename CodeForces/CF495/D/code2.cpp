//#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>

using namespace std;

typedef long long int ll;


void solution(ll n, vector<ll> a){

    ll largest = 0;
    map <ll, ll> distances;
    for(auto x : a) {
        if(distances.count(x) == 0)
            distances[x] = 1;
        else
            distances[x] += 1;
        largest = (x > largest ? x : largest);
    }

    // check if it's possible
    // 0 must exist
    // 1 can exist, but if it does, its count cannot exceed 4
    // there can't be a jump of 2 in the distances
    // no number can exceed 8 counts
    // the largest number cannot exceed 4
    // tick the first few numbers to not have 8.. 7.. 6.. 5..
    // after that make sure that the numbers decrease thereafter!
    // nope.. more complicated than that..


    bool failed = false;
    if(distances.count(0) == 0 || (distances.count(1) != 0 and distnaces[1] > 4)){
        failed = true;
    } else if(distances[largest] > 4) {
        failed = true;  
    } else {
        ll last = 0;
        for(auto& kv : distances) {
            if(kv.first - last > 1 or kv.second > 8){
                failed = true;
                break;
            } 
        }
    }

    if(failed) {
        printf("-1\n");
        return;   
    }

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

