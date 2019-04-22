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

    string t;
    cin >> t;
    
    int n = t.size();
    int last_a = -1;
    for(int i=0; i<n; i++) 
        if(t[i] == 'a')
            last_a = i;
    string s1 = "";
    for(int i=0; i<=last_a; i++) {
        if(t[i] != 'a')
            s1 += t[i];
    }

    int rem = n - last_a - 1;
    int diff = abs(int(s1.size()) - rem);
    //printf("%s %s %d, %d\n", t.c_str(), s1.c_str(), rem, diff);
    if(s1.size() > rem or diff%2 == 1)
        printf(":(\n");
    else {
        string s2 = "";
        for(int i=last_a+1; i<last_a+1+diff/2; i++)
            s1 += t[i];
        for(int i=last_a+1+diff/2; i<n; i++)
            s2 += t[i];
        //printf("%s %s %d\n", s1.c_str(), s2.c_str(), diff);
        
        if(s1 == s2) {
            s1 = "";
            for(int i=0; i<last_a+1+diff/2; i++)
                s1 += t[i];
            printf("%s\n", s1.c_str());

        } else {
            printf(":(\n");
        }
    }
    return 0;
}








