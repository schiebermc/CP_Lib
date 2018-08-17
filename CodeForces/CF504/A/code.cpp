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

void string_to_dict(map<char, ll>& d, string s) {
    for (auto x : s) {
        if(d.find(x) != d.end()) 
            d[x] += 1;
        else
            d[x] = 1;
    }
}

bool solution(string s1, string s2){

    map<char, ll> d1;
    map<char, ll> d2;
   
    string_to_dict(d1, s1); 
    string_to_dict(d2, s2); 


    ll count = (d1.find('*') == d1.end() ? 0 : d1['*']);

    for( auto & kv : d2) {
        ll c1 = kv.second;
        ll c2 = (d1.find(kv.first) == d1.end() ? 0 : d1[kv.first]);
        
        if(c1 > c2) 
            count -= (c1 - c2);

        if(count < 0 ) {
            return false;
        }
    }

    return true;
}

int main() {

    // variables
    ll n, m;
    cin >> n >> m;
    
    if(n > m + 1) {
        printf("NO\n");
        return 0;
    }

    string s1;
    string s2;
    
    cin >> s1;
    cin >> s2;

    string sl = "";
    ll ind1 = 0;
    while(ind1 < n and s1[ind1] != '*') {
        sl += s1[ind1];
        ind1++; 
    }

    string sr = "";
    ind1++;
    while(ind1 < n) {
        sr += s1[ind1];
        ind1++; 
    }
   
    for(ll i=0; i<sl.size(); i++) {
        if(sl[i] != s2[i]){
            printf("NO\n");
            return 0 ;
        }
    }
 
    for(ll i=0; i<sr.size(); i++) {
        if(sr[i] != s2[s2.size()-sr.size()+i]){
            printf("NO\n");
            return 0;
        }
    }
 

    printf("YES\n");
//    bool ans = solution(s1, s2);
//    
//    if(ans)
//        printf("YES\n");
//    else
//        printf("NO\n");
    
    return 0;
}

