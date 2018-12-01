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

class DisjointSet {

private:
    
    ll maxn_;
    vector<ll> size_;
    vector<ll> parent_;

public:
    
    DisjointSet(ll maxn) {
        // with both optimizations - path compression with 
        // union by size, time queries become nearly constant.
        // final amortized time is the inverse Ackermann function
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
        return parent_[v] = find_set(parent_[v]);
    }

    void union_sets(ll a, ll b) {
        // merge the sets in which a and b belong
        // uses size optimizaton
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size_[a] < size_[b])
                swap(a, b);
            parent_[b] = a;
            size_[a] += size_[b];
        }
    }

};


int main() {

    ll n; 
    cin >> n;
    DisjointSet dj(5);

    for(ll i=0 ;i<5; i++)
        dj.make_set(i);

    dj.union_sets(3, 4); 
    for(ll i=0 ;i<5; i++)
        printf("%lld\n", dj.find_set(i)); 

    return 0;
}


