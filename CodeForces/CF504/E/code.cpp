//#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <set>

using namespace std;

typedef int ll;

void query(string x, string & ans);
string try_move(ll i1, ll j1, ll i2, ll j2, string path);

string find_path(ll i, ll j, ll n, string path) {
    
    if(i == n and j == n) {
        return path;
    }

    // try down
    string ans = try_move(i, j, i+1, j, path);  
    if(ans == "YES") {
        string a = find_path(i+1, j, n, path + "D");
        if(a.size() == n)
            return a;
    } 
      
    // try right
    ans = try_move(i, j, i, j+1, path);
    if(ans == "YES") {
        string a = find_path(i, j+1, n, path + "D");
        if(a.size() == n)
            return a;
    }

    return "";
}

string try_move(ll i1, ll j1, ll i2, ll j2, string path) {
    string ans;
    string q1 = ("? " + to_string(i1) + " " +
                        to_string(j1) + " " +  
                        to_string(i2) + " " +  
                        to_string(j2) + " "); 
    query(q1, ans);
    return ans;
}

void solution(ll m){
    string ans = find_path(1, 1, m, "");
    printf("! %s\n", ans.c_str());
}

void query(string x, string &ans) {
    cout<<x<<"\n";
    fflush(stdout);
    cin>>ans;
    if(ans=="BAD")
        exit(0);
}

int main() {

    // variables
    ll n;
    scanf("%d", &n);

    solution(n);
    
    return 0;
}

