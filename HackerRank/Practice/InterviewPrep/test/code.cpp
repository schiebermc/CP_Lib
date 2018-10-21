//#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <set>
#include <climits>
#include <list>

using namespace std;

typedef long long int ll;


void solution(ll n, ll m, vector<ll> a){


}

void solution2(ll n, ll m, vector<ll> a){


}

void validation(ll start_seed, ll end_seed, ll n) {

    for(ll s=start_seed; s<=end_seed; s++) {
        srand(s);
        vector<ll> a;
        for(ll i=0; i<n; i++) {
            a.push_back(rand()%16);
        }
        //for (auto x : a) {
        //    printf("%lld, ", x);
        //}
        //printf("\n");
        //if(solution2(n, a) != solution(n, a)) {
        //    printf("failed at seed: %lld\n", s);
        //}

    }

}

int main() {

    list<ll> stuff;   
    for(ll i=0; i<10; i++)
        stuff.push_back(i);
    
    auto itr = stuff.begin();
    while(itr != stuff.end()) {
        printf("%lld\n", *itr);
        if(*itr == 5){
            stuff.erase(itr);
            itr--;
        }
        itr++;
       // printf("%lld\n", *itr);
       // if(*itr == 5){
       //     itr = stuff.erase(itr);
       // } else {
       //     itr++;
       // }
    }
 
    return 0;
}

