//#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <unordered_set>
#include <set>
#include <queue>

typedef long long int ll;

using namespace std;

class DisjointSet {

private:
    
    ll maxn_;
    vector<ll> size_;
    vector<ll> parent_;

public:
    
    DisjointSet(ll maxn) {
        maxn_ = maxn;
        size_.resize(maxn, 1);
        parent_.resize(maxn_);
    }

    void make_set(ll v) {
        // creates a new set for node v
        parent_[v] = v;
    }
    
    ll find_set(ll v) {
        // returns the parent of the set in which v belongs
        // using path compression optimization
        if (v == parent_[v])
            return v;
        
        printf("(%lld, %lld)\n", v, parent_[v]);
        parent_[v] = find_set(parent_[v]);
        printf("(%lld, %lld)\n", v, parent_[v]);
        
        return parent_[v];
    }

    //void union_sets(ll a, ll b) {
    void union_sets(ll a, ll b, unordered_set<ll> &machines) {
        // merge the sets in which a and b belong
        // uses size optimizaton
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (machines.find(b) != machines.end())
                swap(a, b);
            //if (size_[a] < size_[b])
            //    swap(a, b);
            parent_[b] = a;
            size_[a] += size_[b];
        }
    }

};


int main() {


    ll n, k;
    cin >> n >> k;
    
    // initialize disjoint sets
    DisjointSet dj(n);
    for(ll i=0 ;i<n; i++)
        dj.make_set(i);

    // gather the edges
    ll n1, n2, w;
    vector<tuple<ll, ll, ll>> edges;
    for (ll i=0; i<n-1; i++) {
        scanf("%lld %lld %lld", &n1, &n2, &w);
        edges.push_back(make_tuple(w, n1, n2));
    }

    // get set of machines 
    unordered_set<ll> machines;
    for(ll i=0 ;i<k; i++) {
        scanf("%lld", &n1);
        machines.emplace(n1);
    }

    // sort the edges by weight
    sort(edges.begin(), edges.end());

    // reverse iterate the edges (largest to smallest)
    ll p1, p2, cost = 0;
    auto itr = edges.rbegin();
    while(itr != edges.rend()) {

        w = get<0>(*itr);
        n1 = get<1>(*itr);
        n2 = get<2>(*itr);
        
        p1 = dj.find_set(n1);
        p2 = dj.find_set(n2);

        if(machines.find(p1) != machines.end() and machines.find(p2) != machines.end()) {
            cost += w;
        } else {
            dj.union_sets(p1, p2, machines);
        } 
        itr++;
    }
    

    printf("%lld\n", cost);

    return 0;
}


