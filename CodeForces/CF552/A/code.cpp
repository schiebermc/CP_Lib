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
    ll ab, ac, bc, abc;

    ll i, j, k, l;
    cin >> i >> j >> k >> l;
    vector<ll> vec = {i, j, k, l};
    
    abc = max_element(vec.begin(), vec.end()); 


    return 0;
}

