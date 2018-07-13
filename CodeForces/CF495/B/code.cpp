//#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

typedef long long int ll;

string solution1(ll n, vector<vector<ll>> pairs);

void solution(ll n, ll m){

    // slick trick here..
    for(ll i=0; i<n; i++) {
        if(i%2)
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}

int main() {

    // variables
    ll n, m;
    cin >> n >> m;

    //validation()
    solution(n, m);
    
    return 0;
}

