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
        // with both optimizations - path compression and 
        // union by size, time queries become nearly constant.
        // final amortized time is the inverse Ackermann function
        maxn_ = maxn;
        size_.resize(maxn, 1);
        // do not try to grab parent_ directly!
        // you should be using find_set to 
        // get the correct parent!
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

    vector<ll>& get_sizes() { return size_; }

};

int main() {

    ll n, k; 
    cin >> n >> k;
    DisjointSet dj(n);

    for(ll i=0 ;i<n; i++)
        dj.make_set(i);

    ll a, b, c;
    for(ll i=0; i<n-1; i++){
        scanf("%lld %lld %lld", &a, &b, &c);
        if(c == 1)
            continue;
        dj.union_sets(a-1, b-1);
    }

    // get each unique set 
    set<ll> parents;
    for(ll i=0; i<n; i++)
        parents.emplace(dj.find_set(i));
    ll nsets = parents.size();

    return 0;
}


