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

void merge_sort(vector<ll>& a, ll start, ll stop);
void print_vector(string name, vector<ll>& a);

void solution(vector<ll>& a){
    // merge sort
    // time: O(NlogN)
    // memory: O(n)
    // divide and conquer strategy
    // 1. divide
    // 2. merge_sort
    // 3 combine
    merge_sort(a, 0, a.size()-1);
}

void divide(vector<ll>& a, ll start, ll stop, vector<ll>& l, vector<ll>& r) {
    // stop is inclusive
    ll mid = (stop - start) / 2;
    for (ll i=start; i<=mid; i++) {
        l.push_back(a[i]);
    }
    for (ll i=mid+1; i<=stop; i++) {
        r.push_back(a[i]);
    }
}

void merge_sort(vector<ll>& a, ll start, ll stop){
    
    // base case (single value)
    if(start == stop)
        return; 

    // divide the array
    vector<ll> l;
    vector<ll> r;
    divide(a, start, stop, l, r);
    
    // conquer the subproblems
    merge_sort(l, 0, l.size()-1);
    merge_sort(r, 0, r.size()-1);

    // combine the subproblems
    ll lp = 0;
    ll rp = 0;
    for(ll i=start; i<=stop; i++) {
        if(rp == r.size() or (lp < l.size() and l[lp] < r[rp])) {
            a[i] = l[lp];
            lp++;
        } else {
            a[i] = r[rp];
            rp++;
        }
    }
}

void print_vector(string name, vector<ll>& a) {
    printf("%s\n", name.c_str());
    for(auto x : a) {
        printf("%lld ", x);
    }
    printf("\n");
}

int main() {

    // variables
    ll n;
    cin >> n;

    vector<ll> arr; arr.resize(n);
    for(ll i=0; i<n; i++) {
        scanf("%lld", &arr[i]);
    }
    
    print_vector("vector before sorting: ", arr);
    solution(arr);
    print_vector("vector after  sorting: ", arr);
    
    return 0;
}

