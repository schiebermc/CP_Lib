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
using namespace std;
typedef long long int ll;

int is_palindrome(string s) {
    for(int i=0, j=s.size()-1; i<s.size()/2; i++, j--) 
        if(s[i] != s[j])
            return 0;
    return 1;
}
 
ll solution4(string S) {
    ll N = S.size();
    unordered_map<char, set<int>> positions;
    for(ll i=0; i<N; i++) {
        if(positions.find(S[i]) == positions.end())
            positions[S[i]] = {};
        positions[S[i]].emplace(i);
    }

    string s1;
    vector<vector<int>> pr(N);
    for(int i=0; i<N; i++) {pr[i] = vector<int>(N);}
    for(ll i=0; i<N; i++) {
        s1 = "";
        for(ll j=i; j<N; j++) {
            s1 += S[j];
            pr[i][j] = is_palindrome(s1);
        }
    }

    vector<vector<int>> prf(N);
    for(int i=0; i<N; i++) {prf[i] = vector<int>(N);}
    for(ll i=0; i<N; i++) {
        prf[i][i] += pr[i][i];
        for(ll j=i+1; j<N; j++) {
            prf[i][j] = prf[i][j-1] + pr[i][j];
        }
    }

    vector<vector<int>> prb(N);
    for(int i=N-1; i>=0; i--) {prb[i] = vector<int>(N);}
    for(ll j=N-1; j>=0; j--) {
        prb[j][j] = pr[j][j];
        for(ll i=j-1; i>=0; i--) {
            prb[i][j] = prb[i+1][j] + pr[i][j];
        }
    }
    
    vector<unordered_map<int, int>> self_matches; self_matches.resize(N);
    for(ll i=0; i<N; i++) {
        for(auto x : positions[S[i]])
            if(x > i) {
                ll this_count = 0;
                this_count++;
                this_count += prf[i+1][x-1] - prf[i+1][i];
                this_count += prb[i+1][x-1] - prb[x][x-1];
                self_matches[i][x] = this_count;;
            }
    }
    
    vector<unordered_set<int>> adj_matches; adj_matches.resize(N);
    for(ll i=0; i<N-1; i++) {
        for(auto kv : self_matches[i+1]) {
            int index = kv.first;
            if(self_matches[i].find(index+1) != self_matches[i].end())
                adj_matches[i].emplace(index);
        }
    }

    vector<unordered_map<int, ll>> dp; dp.resize(N);
    for(ll i=N-2; i>=0; i--) {
        for(auto x : adj_matches[i]) {
            ll count = self_matches[i+1][x];
            if(adj_matches[i+1].find(x-1) != adj_matches[i+1].end())
                count += dp[i+1][x-1];
            dp[i][x] = count;
        }
    }
 
    ll count = 0;
    for(ll i=0; i<N; i++) 
        for(auto x : self_matches[i])
            count += x.second;
    
    for(ll i=0; i<N; i++) 
        for(auto kv : dp[i]) 
            count += kv.second;

    return count;
}

int main() {

    string S;
    cin >> S;
    printf("%lld\n", solution4(S));

    return 0;
}

