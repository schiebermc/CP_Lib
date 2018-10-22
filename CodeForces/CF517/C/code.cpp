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

void size_and_contents(vector<ll>& v);

void solution(ll a, ll b){

    // maximum number of pages we can read is n + m
    // therefore the largest number x for which 0.5x(x+1) <= n + m 
    // is the largest possible page we can read

    // determine x
    ll x = 1;
    while(x*(x+1)/2 <= a + b) 
        x++;
    x--;
    
    //printf("x: %lld\n", x);
       
    // the total number of pages will be x or x-1
    vector<ll> A;
    vector<ll> B;
    bool placed = false;
    ll flagged = -1;
    ll tots = 0;
    for(ll i=x; i>0; i--) {
    
        if(i == flagged)
            continue;

        if(placed) {
            B.push_back(i);
        } else {
            if(tots + i == a) {
                A.push_back(i);
                placed = true;
            } else if(tots + i > a) {
                ll diff = a - tots;
                if(diff > 0){
                    A.push_back(diff);
                    flagged = diff;
                }
                if(i <= b) {
                    B.push_back(i);
                }
                placed = true;
            } else {
                A.push_back(i);
                tots += i;
            }
        }
    }
    size_and_contents(A);
    size_and_contents(B);
}

void size_and_contents(vector<ll>& v) {
    printf("%zu\n", v.size());
    for(auto x : v)
        printf("%lld ", x);
    printf("\n");
}


int main() {

    // variables
    ll n, m;
    cin >> n >> m;

    //validation(0, 10, 10)
    solution(n, m);
    
    return 0;
}

