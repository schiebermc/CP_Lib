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

    void remove_edge(ll n1, ll n2) {
        // removes the edge between n1 and n2
        if(G_[n1].find(n2) != G_[n1].end()) 
            G_[n1].erase(n2);
        if(G_[n2].find(n1) != G_[n2].end()) 
            G_[n2].erase(n1);
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
    
    vector<ll> component_counts_special(set<ll> machines) {
        // returns the counts of all components in G_
        // number of nodes in each component
        // weakly ordered
        // instead of returning the number of nodes in each compenent,
        // this function returns the number of machines 

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

                it2 = frontier.begin();
                ll node2 = *it2;
                frontier.erase(it2);   // amortized
                to_visit.erase(node2); // logorithmic by value
                visited.emplace(node2);
 
                if(machines.find(node2) != machines.end())
                    count++; 
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
ll max_vec(vector<ll> vec) {
    ll best = 0;
    for (auto x : vec){
        if(x > 1)
            best += x;

    }
    return best;
}

int main() {

    ll n, k;
    cin >> n;
    cin  >> k;

    vector<tuple<ll, ll, ll>> edges;
    ll n1, n2, w;
    Graph graph = Graph(n);
    for (ll i=0; i<n-1; i++) {
        scanf("%lld %lld %lld", &n1, &n2, &w);
        graph.add_edge(n1, n2, w); 
        edges.push_back(make_tuple(w, n1, n2));
    }

    set<ll> machines;
    for(ll i=0 ;i<k; i++) {
        scanf("%lld", &n1);
        machines.emplace(n1);
    }
    
    ll cost = 0;
    ll ind = 0;
        
    ll prev_max;
    auto vec = graph.component_counts_special(machines);
    //printf("ind: %lld -- ", ind);
    //for (auto x : vec) 
    //    printf("%lld, ", x);
    //printf("\n"); 

    sort(edges.begin(), edges.end());
    set<ll> used;
    while(max_vec(vec) > 1) {
        if(ind == n-1){
            ind = 0;
        }    
    
        if(used.find(ind) != used.end())
            continue;

        w  = get<0>(edges[ind]);        
        n1 = get<1>(edges[ind]);        
        n2 = get<2>(edges[ind]);        
        prev_max = max_vec(vec);
        graph.remove_edge(n1, n2);
        vec = graph.component_counts_special(machines);

//        printf("ind: %lld -- %lld -- ", ind, w);
//        for (auto x : vec) 
//            printf("%lld, ", x);
//        printf("\n"); 
    
        if(prev_max == max_vec(vec)){ // didn't work 
            graph.add_edge(n1, n2, w);   
        } else {
            cost += w;
            used.emplace(ind);
        }
        ind++;
    }  
    
    
    printf("%lld\n", cost);
    return 0;
}

