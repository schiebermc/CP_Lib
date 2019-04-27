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

void fail() {
   cout << "NO" << endl;
   exit(0);
}

int main() {

    IOS;
    ll n, k;
    cin >> n >> k;

    ll lbound = (k*(k+1))/2;
    ll diff = n - lbound;
    ll x = 1 + diff / k;
   
    lbound = (k*(k+1))/2 + (x-1)*k;
    diff = n - lbound;
    
    vector<int> ans; ans.reserve(k);
    for(int i=0; i<k; i++) {
        ans.push_back(x+i);
    }

    int bumped = 0;
    for(int i=1; i<k; i++) {
        if(diff == 0) {
            for(int j=i; j<k; j++)
                ans[j] += bumped;
            break;
        }
        ll impact = k-i;
        ll bump = min(2*ans[i-1] - ans[i], int(diff / impact));        
        
        diff -= impact * bump; 
        bumped += bump;
        ans[i] += bumped;
    }   
    
    for(int i=1; i<k; i++) {
        if(ans[i] > 2*ans[i-1])
            fail();
        if(ans[i] <= ans[i-1])
            fail();
    } 
   
    if(diff)
        fail();
    
    cout << "YES" << endl;
    for(auto x : ans)
        cout << x << ' ';
    cout << endl; 

    return 0;
}




