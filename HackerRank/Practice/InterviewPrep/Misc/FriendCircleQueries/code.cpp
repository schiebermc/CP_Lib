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
    ll largest_set_size_ = 1;

public:
    
    DisjointSet(ll maxn) {
        // with both optimizations - path compression with 
        // union by size, time queries become nearly constant.
        // final amortized time is the inverse Ackermann function
        maxn_ = maxn;
        size_.resize(maxn, 1);
        parent_.resize(maxn_);
    }

    ll largest_set_size() {
        return largest_set_size_;
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
            largest_set_size_ = max(largest_set_size_, size_[a]);
        }
    
    }

};


int main() {

    ll n; 
    cin >> n;
    DisjointSet dj(2*pow(10, 5));

    bool in1, in2;
    map<ll, ll> index;
    ll n1, n2, ind = 0;

    for(ll i=0; i<n; i++) {
        
        scanf("%lld %lld", &n1, &n2);
        in1 = index.find(n1) != index.end();
        in2 = index.find(n2) != index.end();
  
        if(not in1) {
            index[n1] = ind;
            dj.make_set(ind);
            ind++;
        } 
        
        if(not in2) {
            index[n2] = ind;
            dj.make_set(ind);
            ind++;
        } 
        
        dj.union_sets(index[n1], index[n2]);
    
        printf("%lld\n", dj.largest_set_size());
    
    }

    return 0;
}


