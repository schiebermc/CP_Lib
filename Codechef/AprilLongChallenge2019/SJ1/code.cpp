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
typedef long long ll;
void add_edge(unordered_map<int, vector<int>> &edges, int& u, int& v) {
   if(edges.find(u) == edges.end())
       edges[u] = {};
   edges[u].push_back(v);
}

ll find_gcd(ll x, ll y){ 
    while(y) { 
        ll tmp = y;   
        y = x % y;
        x = tmp;
    }
    return x;
}

void direct_edges(unordered_map<int, vector<int>>& undirected_edges, int root, int parent, vector<ll>& ans, vector<ll>& V, vector<ll>& M, ll gcd){
    
    int childs = 0;
    for(auto x : undirected_edges[root]) {
        if(x == parent)
            continue;
        childs++;
        direct_edges(undirected_edges, x, root, ans, V, M, find_gcd(V[x-1], gcd));
    }

    if(childs == 0)
        ans[root-1] = M[root-1] - find_gcd(M[root-1], gcd);
}

int main() {

    IOS;
    int t, N, u, v;
    cin >> t;

    ll Nmax = 1e5;
    vector<ll> V; V.resize(Nmax);
    vector<ll> M; M.resize(Nmax);
    vector<ll> ans; ans.resize(Nmax, -1);
    for(ll test=0; test<t; test++) {

        cin >> N; 
        unordered_map<int, vector<int>> undirected_edges;
        for(ll i=0; i<N-1; i++) { 
            cin >> u >> v;
            add_edge(undirected_edges, u, v);
            add_edge(undirected_edges, v, u);
        } 

        for(ll i=0; i<N; i++) { cin >> V[i]; }
        for(ll i=0; i<N; i++) { cin >> M[i]; }
        
        direct_edges(undirected_edges, 1, 0, ans, V, M, V[0]);

        for(ll i=0; i<Nmax; i++) {
            if(ans[i] >= 0) {
                printf("%lld ", ans[i]);
                ans[i] = -1;
            }
        }
        printf("\n");

    }

    return 0;
}

