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

void check_add(map<char, ll>& s, char c);


void solution(ll n, string a, string b){

    ll count = 0;
    for(ll i=0; i<n/2; i++) {
        map<char, ll> stuff;
        check_add(stuff, a[i]);
        check_add(stuff, b[i]);
        check_add(stuff, a[n-1-i]);
        check_add(stuff, b[n-1-i]);
        ll items = stuff.size();
        ll max_val = 0;
        for (auto kv : stuff) {
            max_val = (max_val < kv.second ? kv.second : max_val);
        }
        
        if(items == 4){
            count += 2;
        } else if (items == 3) {
            if(a[i] != a[n-1-i]) 
                count++;
            else
                count += 2;
        } else if (items == 2 and max_val == 3) {
            count += 1;
        }
    }
    
    if(n%2 == 1) {
        if(a[n/2] != b[n/2]){
            count++;
        }
    }
    printf("%lld\n", count);

}

void check_add(map<char, ll>& s, char c){
    if(s.count(c) == 0) {
        s[c] = 1;
    } else {
        s[c] += 1;
    }

}


int main() {

    // variables
    ll n;
    cin >> n;

    string a, b;
    cin >> a >> b;
   
    //validation(0, 10, 10)
    solution(n, a, b);
    
    return 0;
}

