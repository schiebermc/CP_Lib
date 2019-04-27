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
    ll n;
    cin >> n;

    string s;
    cin >> s;
    vector<int> a; a.resize(n);
    for(ll i=0; i<n; i++) {
        a[i] = int(s[i])-48;
    }
    
    vector<int> m; m.resize(9);
    for(ll i=0; i<9; i++) {
        cin >> m[i];
    }
    
    vector<int> ans;
    bool started = false;
    for(int i=0; i<n; i++) {
        int num1 = a[i];
        int num2 = m[num1-1];
        
        if(started) {
            if(num2 >= num1) 
                ans.push_back(num2);        
            else
                break; 
        } else {
            if(num2 > num1) {
                started = true;
                ans.push_back(num2);        
            }  else {
                ans.push_back(num1);
            }     
        }

    }

    for(int i=ans.size(); i<n; i++) {
        ans.push_back(a[i]);
    }

    for(auto x : ans)
        cout << x;
    cout << endl;

    return 0;
}




