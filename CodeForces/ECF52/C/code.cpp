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

void make_good_slice(ll n, ll k, map<ll, ll>& a);
void get_largest_two_keys(ll& largest, ll& second_largest, map<ll, ll>& a);


void solution(ll n, ll k, map<ll, ll>& a){

    ll count = 0;
    bool done = a.size() == 1 and a.find(0) != a.end();
    while(!done) {
        make_good_slice(n, k, a);
        count++;
        done = (a.size() == 1);
    }
    printf("%lld\n", count);

}

void get_largest_two_keys(ll& largest, ll& second_largest, map<ll, ll>& a) {
    auto itr = a.end();
    itr--;
    largest = itr->first;
    itr--;
    second_largest = itr->first;
}

void make_good_slice(ll n, ll k, map<ll, ll>& a) {

    ll l1, l2, tmp, diff;
    ll sliced = 0;
    bool done_slicing = false;

    while(!done_slicing and sliced <= k) {
    
        //printf("%lld, %lld\n", a.size(), sliced);
        if(a.size() > 1) {
            
            get_largest_two_keys(l1, l2, a);
            diff = l1 - l2;
            tmp = a[l1] * diff;
            
            if(tmp + sliced > k) { // did i take off too much?
                diff = (k - sliced) / a[l1];
                
                if(l1 - diff <= l2)
                    throw;
                else if(diff == 0)
                    done_slicing = true;
                else { 
                    tmp = diff * a[l1];      
                    sliced += tmp;
                    a[l1-diff] = a[l1];
                    auto itr = a.end();
                    itr--;
                    a.erase(itr);                
                }
    
            } else { // apply it
                sliced += tmp;
                a[l2] += a[l1];
                auto itr = a.end();
                itr--;
                a.erase(itr);                
            }

        } else {
            done_slicing = true;
        }

    }


}

int main() {

    // variables
    ll n, m;
    cin >> n >> m;

    ll k;
    map<ll, ll> stuff;
    for(ll i=0; i<n; i++) {
        scanf("%lld", &k);
        if(stuff.find(k) == stuff.end())
            stuff[k] = 1;
        else
            stuff[k]++;
    }
    
    //validation(0, 10, 10)
    solution(n, m, stuff);
    
    return 0;
}

