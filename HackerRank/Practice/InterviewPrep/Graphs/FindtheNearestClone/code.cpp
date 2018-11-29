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
   
    // use these to go slightly faster. idk if it's necessary
    // hackerrank is a joke 
    map<ll, ll>::iterator get_neighbors_begin_iter(ll n) {
        return G_[n].begin();
    }
    
    map<ll, ll>::iterator get_neighbors_end_iter(ll n) {
        return G_[n].end();
    }

    ll bfs_same_color(ll node1, vector<ll> colors) {
        // returns the shortest distance between node1 and any node 
        // of the same color
        // adds distance as node to node.  does not use graph weights!

        ll color = colors[node1];
        ll distance = -1;    
        set<ll> visited;
        queue<pair<ll, ll>> frontier;
        frontier.push(make_pair(node1, 0));
        
        while(frontier.size() != 0) {
   
                pair<ll, ll> next = frontier.front();
                ll node2 = get<0>(next);
                ll dist = get<1>(next);
                frontier.pop();
                visited.emplace(node2);                

                if(colors[node2] == color and node2 != node1) {
                    distance = dist;
                    break;
                }

                auto itr1 = get_neighbors_begin_iter(node2);
                auto itr2 = get_neighbors_end_iter(node2);
                //for (auto neighbor :  get_neighbors(node2)) {
                //for (auto &kv : G_[node2]) {
                //    auto neighbor = kv.first;
                while(itr1 != itr2) {
                    auto neighbor = itr1->first;
                    if(visited.find(neighbor) == visited.end()) {
                        frontier.push(make_pair(neighbor, dist+1));
                    }
                    itr1++;
                }
        }
        return distance;
    }

    ll BFS_distance(ll n1, ll n2) {
        // returns the shortest BFS distnace between n1 and n2
        // faster than uniform cost, since no priority queue is needed
        // BFS frontier = queue    
        // adds distance as node to node.  does not use graph weights!
    
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

void solution(Graph graph, vector<ll> colors, ll node) {

    ll val = graph.bfs_same_color(node-1, colors);
    printf("%lld\n", val); 

}

int main() {

    ll n, m;
    cin >> n >> m;
    Graph graph = Graph(n);

    ll n1, n2;
    for(ll i=0; i<m; i++) {
        scanf("%lld %lld", &n1, &n2);
        graph.add_edge(n1-1, n2-1, 1);
    }

    vector<ll> colors; colors.resize(n);
    for(ll i=0; i<n; i++) {
        scanf("%lld ", &colors[i]);
    }

    ll node;
    cin >> node;    

    solution(graph, colors, node);
    
    return 0;
}

