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

ll solution_recursive(ll i, ll j, vector<ll> path, ll n, ll m, ll k, vector<vector<ll>> a);
ll check_path(vector<ll> path, ll k);

void solution(ll n, ll m, ll k, vector<vector<ll>> a){
    
    ll count = solution_recursive(0, 0, {}, n, m, k, a);
    printf("%lld\n", count);
}

ll solution_recursive(ll i, ll j, vector<ll> path, ll n, ll m, ll k, vector<vector<ll>> a) {

    ll count = 0;
    if(i == n-1 and j == m-1) {
        path.push_back(a[i][j]);
        return check_path(path, k);
    } 

    path.push_back(a[i][j]);
    if (i != n-1) {
        count += solution_recursive(i+1, j, path, n, m, k, a);
    } 

    if (j != m-1) {
        count += solution_recursive(i, j+1, path, n, m, k, a);
    }

    return count;

}

ll check_path(vector<ll> path, ll k) {
    ll ans = path[0];
    for(ll i=1; i<path.size(); i++) 
        ans ^= path[i];
    if(ans == k) 
        return 1;
    else
        return 0;
}

int main() {

    // variables
    ll n, m, k;
    cin >> n >> m >> k;

    vector<vector<ll>> arr; arr.resize(n);
    for(ll i=0; i<n; i++) {
        arr[i].resize(m);
        for(ll j=0; j<m; j++) {
            scanf("%lld", &arr[i][j]);
        }
    }
    
    //validation(0, 10, 10)
    solution(n, m, k, arr);
    
    return 0;
}

