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
void counting_sort(vector<ll>& a, ll lower, ll uper);
void print_vector(string name, vector<ll>& a);

void solution(vector<ll>& a){
    counting_sort(a, 0, 100);
}

void counting_sort(vector<ll>& a, ll lower, ll upper){
    vector<ll> counts(upper - lower + 1, 0);
    for (auto x : a) 
        counts[x] += 1;
    for (ll i=0, aind=0; i<counts.size(); i++) {
        for(ll j=0; j<counts[i]; j++, aind++)
            a[aind] = lower+i;
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

