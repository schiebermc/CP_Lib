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
#include <stack>

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long int ll;

int main() {

    int t; 
    cin >> t;
   
    for(int test=0; test<t; test++) {
        int n;
        cin >> n;

        unordered_set<int> set1; 
        for(int i=2; i<=n; i++) {set1.insert(i);} 
        printf("%d %d %d ", 1, n-1, 1);
        for(auto x : set1)
            printf("%d ", x);
        printf("\n");            
        fflush(stdout);
        int furthest;
        cin >> furthest;
        
        while(set1.size() != 1) {
            unordered_set<int> set2;
            auto itr = set1.begin();
            int count = 0;
            int split = set1.size() / 2;
            while(itr != set1.end() and count<split) {
                set2.insert(*itr);
                itr = set1.erase(itr);
                count++; 
        
            }
       
            printf("%d %zu %d ", 1, set1.size(), 1);
            for(auto x : set1)
                printf("%d ", x);
            printf("\n");            
            fflush(stdout);

            int distance;
            cin >> distance;
            if(distance != furthest)
                set1 = set2;
        }
     
        int furthest_node = *set1.begin(); 
        for(int i=1; i<=n; i++) {set1.emplace(i);} 
        set1.erase(furthest_node);
        printf("%d %d %d ", 1, n-1, furthest_node);
        for(auto x : set1)
            printf("%d ", x);
        printf("\n");            
        fflush(stdout);
        int ans; 
        cin >> ans;
        
        printf("%d %d\n", -1, ans);
        fflush(stdout);
    }

    return 0;
}

