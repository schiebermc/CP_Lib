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
    ll n, k;
    cin >> n >> k;

    map<int, int> skills;
    vector<int> a; a.resize(n);
    for(ll i=0; i<n; i++) { 
        cin >> a[i];
        skills[a[i]] = i;
    }
   
    vector<int> teams; teams.resize(n);
    int turn = 0;
    int pushed = 0;
    int team;
    int leftmost = -1;
    int rightmost = n;
    while(pushed < n) {

        int maxe = skills.rbegin()->first;
        int start_ind = skills[maxe];
    
        if(turn%2 == 0) 
            team = 1;
        else 
            team = 2;

        skills.erase(maxe);
        teams[start_ind] = team;        
        a[start_ind] = -1;
        pushed++;

        int mates = 0;
        int ind = start_ind;
        while(mates < k) {
            ind--;
            if(ind <= leftmost){
                leftmost = start_ind;
                break;
            }
            if(a[ind] == -1)
                continue;
            int skill = a[ind];    
            a[ind] = -1;
            skills.erase(skill);
            teams[ind] = team;        
            mates++;
            pushed++;
        }

        mates = 0;
        ind = start_ind;
        while(mates < k) {
            ind++;
            if(ind >= rightmost){
                rightmost = start_ind;
                break;
            }
            if(a[ind] == -1)
                continue;
            int skill = a[ind];    
            a[ind] = -1;
            skills.erase(skill);
            teams[ind] = team;        
            mates++;
            pushed++;
        }
        turn++;
    }    

    for(auto x : teams)
        printf("%d", x);
    printf("\n");
     
    return 0;
}

