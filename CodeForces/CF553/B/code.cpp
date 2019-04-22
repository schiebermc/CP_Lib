//#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <bitset>

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long int ll;

int main() {

    IOS;
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a; a.resize(n);
    for(ll i=0; i<n; i++) {
        a[i].resize(m);
        for(ll j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }


    return 0;
}

