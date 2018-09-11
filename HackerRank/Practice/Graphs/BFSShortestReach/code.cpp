//#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <set>
#include <queue>

typedef long long int ll;

using namespace std;

class Graph {

private:

    // graph is represented as:
    // <node1 : node2 : weight12
    // assumes zero based indexing for vector
    ll n_;
    vector<map<ll, ll>> G_;

public:

    Graph(ll n) {
        n_ = n;
        G_.resize(n);
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
        if(G_[n2].count(n1) != 0) {
            if(w < G_[n2][n1]) {
                G_[n2][n1] = w;
            }
        } else {
            G_[n2][n1] = w;
        }

    }

    set<ll> get_neighbors(ll n) {
        set<ll> neighbors;
        for(auto &kv : G_[n]) {
            neighbors.emplace(kv.first);
        }
        return neighbors;
    }

    ll BFS_distance(ll n1, ll n2) {
        // returns the shortest BFS distnace between n1 and n2
        // faster than uniform cost, since no priority queue is needed
        // BFS frontier = queue    
    
        set<ll> visited;
        queue<pair<ll, ll>> frontier;
        frontier.push(make_pair(n1, 0));
        
        while(frontier.size() != 0) {
   
                pair<ll, ll> next = frontier.front();
                ll node = get<0>(next);
                ll dist = get<1>(next);
                frontier.pop();
                visited.emplace(node);                

                if(node == n2)
                    return dist;

                for (auto neighbor :  get_neighbors(node)) {
                    if(visited.find(neighbor) == visited.end()) {
                        frontier.push(make_pair(neighbor, dist+1));
                    }
                }
                
        }
        return -1;

    }

    vector<ll> total_BFS_distance(ll n1) {
        // returns the shortest BFS distnace between n1 and all other nodes
    
        set<ll> visited;
        vector<ll> ans(n_, -1);   
        queue<pair<ll, ll>> frontier;
        frontier.push(make_pair(n1, 0));
     
        while(frontier.size() != 0) {
   
                pair<ll, ll> next = frontier.front();
                ll node = get<0>(next);
                ll dist = get<1>(next);
                frontier.pop();
                
                if(visited.find(node) == visited.end()){
                    visited.emplace(node);                
                    ans[node] = dist;
                } else {
                    continue;
                }

                for (auto neighbor :  get_neighbors(node)) {
                    if(visited.find(neighbor) == visited.end()) {
                        frontier.push(make_pair(neighbor, dist+1));
                    }
                }
                
        }
        return ans;
    
    }

    vector<ll> component_counts() {
        // returns the counts of all components in G_
        // number of nodes in each component
        // weakly ordered

        set<ll> to_visit, visited;
        for(ll i=0; i<n_; i++) {
            to_visit.emplace(i);
        }

        set<ll> frontier;
        vector<ll> counts;
        set<ll>::iterator it1, it2;
        while(to_visit.size() != 0) {

            ll count = 0;
            it1 = to_visit.begin();
            ll node1 = *it1;
            to_visit.erase(it1); // amortized 
            frontier.emplace(node1); 
               
            while(frontier.size() != 0) {

                count++;
                it2 = frontier.begin();
                ll node2 = *it2;
                frontier.erase(it2);   // amortized
                to_visit.erase(node2); // logorithmic by value
                visited.emplace(node2);
   
                for (auto neighbor :  get_neighbors(node2)) {
                    if(visited.find(neighbor) == visited.end()) {
                        frontier.emplace(neighbor);
                    }
                }
                
            }
            counts.push_back(count);
        }
        return counts;
    }

};

void solution(Graph graph) {

    ll s;
    cin >> s;
    s -= 1;
    vector<ll> ans = graph.total_BFS_distance(s);
    for(ll i=0; i<ans.size(); i++) {
        if(i == s)
            continue;
        if(ans[i] == -1)    
            printf("%lld ", ans[i]);
        else
            printf("%lld ", ans[i]*6);
    }
    printf("\n");
}

int main() {

    ll q;
    cin >> q;
    
    for(ll j=0; j<q; j++) {

        ll n, m;
        cin >> n >> m;
        Graph graph = Graph(n);

        ll n1, n2;
        for(ll i=0; i<m; i++) {
            scanf("%lld %lld", &n1, &n2);
            graph.add_edge(n1-1, n2-1, 0);
        }

        solution(graph);
    
    }

    return 0;
}

