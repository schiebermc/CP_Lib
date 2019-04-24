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
    int x;
    cin >> x;
 
    int ops = 0; 
    bool done = false; 
    vector<pair<int, int>> steps;
    for(int i=2; i<32; i++) {

        // odd step
        done = true;
        string s = std::bitset< 32 >(x).to_string();
        for(int j = i; j<32; j++) {
            if(s[j] == '0'){
                done = false;
                break;
            }
        }
        if(done)
            break;

        if(s[i] == '0') {
            int e = 32 - i;
            int y = pow(2, e) - 1;
            x = x ^ y;
            steps.push_back({e, x});
        
        } else {
            continue;
        }
        ops++;
        
        // even step
        done = true;
        s = std::bitset< 32 >(x).to_string();
        for(int j = i; j<32; j++) {
            if(s[j] == '0'){
                done = false;
                break;
            }
        }
        if(done)
            break;
        x++;
        ops++;
    } 
    
            
    printf("%d\n", ops);
    for(auto t : steps)
        printf("%d ", t.first);
    printf("\n"); 


    //printf("%d\n", x);
    return 0;
}

