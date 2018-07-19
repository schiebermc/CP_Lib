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

// O(>2^n) solution
ll solution_recursive(ll i, ll j, vector<ll> path, ll n, ll m, ll k, vector<vector<ll>> a);
ll check_path(vector<ll> path, ll k);

void solution1(ll n, ll m, ll k, vector<vector<ll>> a){
    
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
    //for(auto x : path) {
    //    printf("%lld, ", x);
    //}
    //printf("\n");
    ll ans = path[0];
    for(ll i=1; i<path.size(); i++) 
        ans ^= path[i];
    if(ans == k) 
        return 1;
    else
        return 0;
}

// O(2^n) solution
void gather_top(ll val, ll i, ll j, ll& n, ll& m, vector<vector<ll>>& a, map<pair<ll, ll>, map<ll, ll>>& top) {

    if(i == 0 and j == 0) {
        val = a[i][j];
    } else {
        val ^= a[i][j];
    }

    if(i + j == min(n, m)-1) {
        pair<ll, ll> p = make_pair(i, j); 
        if(top.count(p) != 0 and top[p].count(val) != 0) {
            top[p][val] += 1;   
        } else {
            top[p][val] = 1;
        }           
    } else { 
        if (i != n-1) {
            gather_top(val, i+1, j, n, m, a, top);
        } 
        if (j != m-1) {
            gather_top(val, i, j+1, n, m, a, top);
        }
    }
}

ll count_paths(ll val, ll i, ll j, ll& n, ll& m, vector<vector<ll>>& a, map<pair<ll, ll>, map<ll, ll>>& top) {

    ll count = 0;
    val ^= a[i][j];
    
    if(i+j == min(n, m)) {
        if(i-1 >= 0) {
            count += (top[make_pair(i-1, j)].count(val) != 0 ? top[make_pair(i-1, j)][val] : 0);
        }
        if(j-1 >= 0) {
            count += (top[make_pair(i, j-1)].count(val) != 0 ? top[make_pair(i, j-1)][val] : 0);
        }
    } else {
        if (i != 1) {
            count += count_paths(val, i-1, j, n, m, a, top);
        } 
        if (j != 1) {
            count += count_paths(val, i, j-1, n, m, a, top);
        }
    }
    return count;

}

void solution2(ll n, ll m, ll k, vector<vector<ll>> a){

    if(n == 1 and m == 1) {
        if(a[0][0] == k)
            printf("1\n");
        else
            printf("0\n");
        return;
    }
    
    map<pair<ll, ll>, map<ll, ll>> top;
    gather_top(0, 0, 0, n, m, a, top);

    //for(auto p : top) {
    //    printf("(%lld, %lld): ", get<0>(p.first), get<1>(p.first));
    //    for(auto x : p.second) {
    //        printf("%lld, ", x);
    //    }
    //    printf("\n");
    //}

    ll count = count_paths(k, n-1, m-1, n, m, a, top);
    printf("%lld\n", count);
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
    //solution1(n, m, k, arr);
    solution2(n, m, k, arr);

    return 0;
}

