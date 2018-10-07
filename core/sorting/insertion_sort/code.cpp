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

void solution(vector<ll>& a){
    // insertion sort
    // O(n^2)
    // simple N^2 scan containing superflous comparisons
    // sorted from the front to the back
    for(ll i=1; i<a.size(); i++) {
        ll j = i-1;
        ll val = a[i];
        while(j >= 0 and a[j] > val) {
            // move a[j] back
            // that's why we saved val
            a[j+1] = a[j]; 
            j--;
        }
        // insert a[i] where it belongs
        a[j+1] = val;
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

