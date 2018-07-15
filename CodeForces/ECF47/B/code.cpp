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

void solution(vector<ll> s){

    ll ind = 0;
    ll ones = 0;
    vector<vector<ll>> stuff;
    stuff.push_back({0, 0, 0});

    for(auto x : s) {
        stuff[ind][x] += 1;
        if(x == 2) {
            stuff.push_back({0, 0, 0});
            ind++;
        } else if (x  == 1) {
            ones++;
        }
    }   


    for(ll i=0; i<stuff[0][0]; i++) {
        printf("0");
    }
    for(ll i=0; i<stuff[0][1]; i++) {
        printf("1");
    }
    
    if(stuff.size() > 1) {
        for(ll i=0; i<ones-stuff[0][1]; i++){
            printf("1");
        }        
        printf("2");
        for (ll i=1; i<stuff.size(); i++) {
            vector<ll> x = stuff[i];
            for(ll i=0; i<x[0]; i++) {
                printf("0");
            }
            for(ll i=0; i<x[2]; i++) {
                printf("2");
            }
        }

    } else {
        for(ll i=0; i<stuff[0][2]; i++) {
            printf("2");
        }
    }
    printf("\n");

}

int main() {

    // variables
    string s;
    cin >> s;
    
    vector<ll> s2;
    for(auto x : s) {
        s2.push_back((int)x - 48);
    }
    
    solution(s2);
    
    return 0;
}

