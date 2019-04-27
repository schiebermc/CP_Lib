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

    vector<ll> a; a.resize(n);
    for(ll i=0; i<n; i++) {
        cin >> a[i];
    }
    
    int ind1 = 0;
    int ind2 = n-1;
    
    int prev = 0;
    vector<char> ans;
    while(ans.size() < n) {
        int num1 = a[ind1];
        int num2 = a[ind2];
        if(num1 <= prev and num2 <= prev)
            break;
        bool push_left = false;
        bool push_right = false;
        if(num1 < num2) {
            if(num1 > prev) 
                push_left = true;
            else
                push_right = true;
        } else {
            if(num2 > prev)
                push_right = true;
            else
                push_left = true;
        }
        if(push_left) {
            ans.push_back('L');
            prev = num1;
            ind1++;
        } else if(push_right) {
            ans.push_back('R');
            prev = num2;
            ind2--;
        } else {
            exit(1);
        }
    }

    cout << ans.size() << endl;
    for(auto x : ans)
        cout << x;
    cout << endl;


    return 0;
}

