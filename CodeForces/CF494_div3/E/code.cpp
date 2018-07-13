//#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>


using namespace std;

typedef long long int ll;


void solution(ll n, ll d, ll k){

    // n : number of nodes
    // d : diameter
    // k : maximum degree of any vertex
    // task: can i build a tree under these constraints?

    ll p;
    ll m = -1;
    ll tots = 0;
    for(p=0; tots < n; p++) {
        tots += pow(k, p);
        m++;
    }  
    
    ll rem = (ll)pow(k, p-2);
    //printf("%lld, %lld\n", tots - n, rem);

    bool surplus = ((ll)pow(k, p-1) - (tots - n) > rem);
    ll D = (surplus ? m + m : m + m - 1) ;   

    if(D <= d){
        printf("YES\n");
        ll j = 2;
        for(ll i=1; j<=n; i++) {
            for (ll l=0; l<k; l++) {
                if(j <= n)
                    printf("%lld %lld\n", i, j);
                j++;
            }
        } 

    } else {
        printf("NO\n");
    }
}

int main() {

    // variables
    ll n, m, k;
    cin >> n >> m >> k;

    //validation()
    solution(n, m, k);
    
    return 0;
}

