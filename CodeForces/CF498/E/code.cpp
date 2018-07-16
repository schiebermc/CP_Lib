//#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <set>
#include <stack>

typedef long long int ll;

using namespace std;

class Graph {

private:

    // <node1 : node2 : weight12
    ll n_;
    vector<map<ll, ll>> G_;
    bool directed_;

public:

    Graph(ll n, bool directed=false) {
        n_ = n;
        G_.resize(n);
        directed_ = directed;
    }

    void add_edge(ll n1, ll n2, ll w) {

        // adds edge between n1 and n2 with weight w
        // assumes zero based indexing!
        // assumes n1 is in G
        // keeps the smallest weight
        
        // add n1 to n2
        if(G_[n1].count(n2) != 0) {
            if(w < G_[n1][n2]) {
                G_[n1][n2] = w;
            }
        } else {
            G_[n1][n2] = w;
        }

        // add n2 to n1
        if(!directed_) {
            if(G_[n2].count(n1) != 0) {
                if(w < G_[n2][n1]) {
                    G_[n2][n1] = w;
                }
            } else {
                G_[n2][n1] = w;
            }
        }
    }

    vector<ll> get_neighbors(ll n) {
        vector<ll> neighbors;
        for(auto &kv : G_[n]) {
            neighbors.push_back(kv.first);
        }
        return neighbors;
    }

    ll get_officer(ll u, ll k){

        ll count = 1;
        ll node = u;
        stack<ll> frontier;
        for(auto x : get_neighbors(u-1)){;
            frontier.push(x);
        }

        while(frontier.size() != 0 and count != k) {

            count++;
            ll node = frontier.top();                    
            frontier.pop();

            for (auto neighbor :  get_neighbors(node)) {
                frontier.push(neighbor);
            }
        
        }
        return node;

    }

};

void solution(Graph graph, ll m) {

    ll u, k;
    for(ll i=0; i<m; i++) {
        cin >> u >> k;
        //scanf("%lld %lld" &u, &k);
        ll officer = graph.get_officer(u-1, k);
        printf("%lld\n", officer+1);
    }
}

int main() {

    ll n, m;
    cin >> n >> m;
    Graph graph = Graph(n, true);

    vector<ll> arr; arr.resize(n-1);
    for(ll i=0; i<n-1; i++) {
        scanf("%lld", &arr[i]);
    }
   
    for(ll i=0; i<n-1; i++) {
        graph.add_edge(arr[i]-1, i+1, 0);
    }
  
    solution(graph, m);

    return 0;
}

