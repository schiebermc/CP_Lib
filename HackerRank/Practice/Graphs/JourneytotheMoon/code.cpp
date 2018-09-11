//#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <set>

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

    ll summ = 0;
    ll count = 0;
    vector<ll> counts = graph.component_counts();
    for(ll i=0; i<counts.size(); i++) {
        count += summ * counts[i];
        summ += counts[i];
    }
    printf("%lld\n", count);

}

int main() {

    int n, m;
    cin >> n >> m;
    Graph graph = Graph(n);

    ll n1, n2;
    for(ll i=0; i<m; i++) {
        scanf("%lld %lld", &n1, &n2);
        graph.add_edge(n1, n2, 0);
    }

    solution(graph);

    return 0;
}

