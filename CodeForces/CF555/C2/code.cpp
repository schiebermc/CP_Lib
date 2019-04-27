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

pair<bool, int> best_from_here(vector<int>& a, int ind1, int ind2) {
    int countl = 0, countr = 0;

    int ind = ind1;
    int prev = a[ind];
    while(ind < ind2) {
        ind++;
        int num = a[ind];
        if(num <= prev)
            break;
        prev = num;    
        countl++;
    }

    ind = ind2;
    prev = a[ind2];
    while(ind1 < ind) {
        ind--;
        int num = a[ind];
        if(num <= prev)
            break;
        prev = num;    
        countr++;
    }

//    printf("c1: %d, c2: %d\n", countl, countr);
    if(countl > countr) {
        return {true, countl};
    } else {
        return {false, countr};
    }
} 

int main() {

    IOS;
    int n;
    cin >> n;

    vector<int> a; a.resize(n);
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
        
        if(num1 == num2) {
            auto p = best_from_here(a, ind1, ind2);
            bool side = p.first;
            int amount = p.second;
            char c = (side ? 'L' : 'R');
            for(int i=0; i<amount+1; i++)
                ans.push_back(c);
            break;
        } else if(num1 < num2) {
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

