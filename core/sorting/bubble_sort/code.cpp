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
void swap(vector<ll>& a, ll i, ll j);

void solution(vector<ll>& a){
    // bubble sort
    // O(n^2)
    // simple N^2 scan containing many superflous comparisons
    // sorted from the front to the back
    for(ll i=0; i<a.size(); i++) {
        for(ll j=i+1; j<a.size(); j++) {
            if(a[i] > a[j]){
                swap(a, i, j);
            }
        }
    }

}

void swap(vector<ll>& a, ll i, ll j) {
    ll tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
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

