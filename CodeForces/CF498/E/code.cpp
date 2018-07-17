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

class Tree {

private:

    // <node1 : node2 : weight12
    ll n_;
    vector<map<ll, ll>> G_;
    bool directed_;
    vector<ll> mos_vec_;
    map<ll, vector<ll>> mos_indices_;

public:
    

    Tree(ll n, bool directed=true) {
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

    void init_mos(ll node=0) {
        // initializes vector and index map for mo's algorithm
        // assumes tree is rooted at node 0
        mos_indices_[node] = {(ll)mos_vec_.size(), 0};
        mos_vec_.push_back(node);
        for(auto neighbor : get_neighbors(node)) {
            init_mos(neighbor);
        }
        mos_indices_[node][1] = mos_vec_.size();
    }
    
    ll get_dfs_distance(ll source, ll k) {
        // returns node that is k distance away
        // uses mo's algorithm: O(sqrt(n)n)
        ll pos = mos_indices_[source][1] - mos_indices_[source][0];
    
        if(pos < k) {
            return -2;
        } else {
            return mos_vec_[mos_indices_[source][0]+k-1];
        }

    }
    
    
};


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

    pair<ll, ll> get_dfs_distance(ll source, ll k, ll count=0){
        // returns node which has a dfs distance of k from 
        // source node.  second item of pair is actual distance,
        // in case there is no node that is k from source.

        count++;
        ll node = source;
        if(count == k) {
            return make_pair(node, count);
        }
        
        for (auto neighbor :  get_neighbors(node)) {
            if(count == k) {
                break;
            } else {
                pair<ll, ll> stuff = get_dfs_distance(neighbor, k, count);
                node  = get<0>(stuff);
                count = get<1>(stuff);
            }
        }
        return make_pair(node, count);                
    }
};

void solution1(Graph graph, ll m) {

    ll u, k;
    for(ll i=0; i<m; i++) {
        //cin >> u >> k;
        scanf("%lld %lld", &u, &k);
        pair<ll, ll> stuff = graph.get_dfs_distance(u-1, k);
        if(get<1>(stuff) == k) {
            printf("%lld\n", get<0>(stuff)+1);
        } else {
            printf("-1\n");
        }
    }

}

void solution2(Tree tree, ll m) {

    ll u, k;
    tree.init_mos();
    for(ll i=0; i<m; i++) {
        scanf("%lld %lld", &u, &k);
        ll officer = tree.get_dfs_distance(u-1, k);
        printf("%lld\n", officer+1);
    }

}

//void validation(ll n, ll m) {
//
//    Tree tree = Tree(n);
//    Graph graph = Graph(n, true);
//
//    for(ll i=1; i<n; i++) {
//        tree.add_edge(i-1, i, 0);
//        graph.add_edge(i-1, i, 0);
//    }
//
//    double T0 = 0.0;
//    double T1 = 0.0;
//   
//    clock_t start = clock();
//    tree.init_mos();
//    clock_t end = clock();
//    T0 += (double) (end-start) / CLOCKS_PER_SEC * 1000.0;
//
//    for(ll i=0; i<m; i++) {
//        ll u = rand() % n;
//        ll k = rand() % n;
//
//        start = clock();
//        ll val1 = tree.get_dfs_distance(u, k);
//        end = clock();
//        T0 += (double) (end-start) / CLOCKS_PER_SEC * 1000.0;
//        
//        start = clock();
//        ll val2;
//        pair<ll, ll> stuff = graph.get_dfs_distance(u, k);
//        if(get<1>(stuff) == k) {
//            val2 = get<0>(stuff);
//        } else {
//            val2 = -2;
//        }
//        end = clock();
//        T1 += (double) (end-start) / CLOCKS_PER_SEC * 1000.0;
//        if(val1 != val2) {
//            printf("Failed ! ~ %lld, %lld\n", val1, val2);
//        }
//    }
//
//    printf("T0: %f\n", T0);
//    printf("T1: %f\n", T1);
//
//}

int main() {

    ll n, m;
    cin >> n >> m;
    Tree graph = Tree(n, true);

    ll node;
    for(ll i=0; i<n-1; i++) {
        scanf("%lld", &node);
        graph.add_edge(node-1, i+1, 0);
    }

    //validation(50000, 1000);  
    solution2(graph, m);

    return 0;
}

