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

pair<ll, ll> get_heaviest_subtree_at_root( unordered_map<ll, pair<ll, vector<ll>>>& tree, vector<ll>& weights, ll node, ll root, ll X) {
         
    ll cuts = 0;
    ll this_subtree = weights[node-1];;

    for(auto child : tree[node].second) {
        auto stuff = get_heaviest_subtree_at_root(tree, weights, child, root, X);
        cuts += stuff.second;
        this_subtree += stuff.first;
    }

    ll cost = this_subtree - cuts*X; 
    if(cost < -X) {
        return {0, 1};
    } else { 
        return  {this_subtree, cuts};
    }
}        

void add_edge(unordered_map<ll, vector<ll>> &edges, ll u, ll v) {
   if(edges.find(u) == edges.end())
       edges[u] = {};
   edges[u].push_back(v);
}

void direct_edges(unordered_map<ll, vector<ll>>& undirected_edges,
                  unordered_map<ll, pair<ll, vector<ll>>>& directed_edges, ll root){
    if(directed_edges.find(root) == directed_edges.end())
        directed_edges[root] = {0, {}};
    for(auto x : undirected_edges[root]) {
        if(x == directed_edges[root].first)
            continue;
        directed_edges[root].second.push_back(x);
        directed_edges[x] = {root, {}};
        direct_edges(undirected_edges, directed_edges, x);
    }
}
            
ll solution3(unordered_map<ll, pair<ll, vector<ll>>>& tree, vector<ll>& A, ll X, ll N) {
    auto stuff = get_heaviest_subtree_at_root(tree, A, 1, 1, X);       
    return stuff.first - stuff.second*X; 
}

int main() {

    IOS;
    ll t, N, X, u, v;
    cin >> t;

    for(ll test=0; test<t; test++) {

        cin >> N >> X;
        vector<ll> A; A.resize(N);
        for(ll i=0; i<N; i++) { cin >> A[i]; }
        
        unordered_map<ll, vector<ll>> undirected_edges;
        for(ll i=0; i<N-1; i++) { 
            cin >> u >> v;
            add_edge(undirected_edges, u, v);
            add_edge(undirected_edges, v, u);
        } 

        unordered_map<ll, pair<ll, vector<ll>>> tree;
        direct_edges(undirected_edges, tree, 1);
        
        printf("%lld\n", solution3(tree, A, X, N));

    }

    return 0;
}

