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

ll mod_power(ll x,ll y,ll p){
    // computes x ^ y % p 
    ll res = 1;
    x = x % p;  
    while (y > 0) {
        if ((y & 1) == 1)  
            res = (res * x) % p ;
        y = y >> 1;
        x = (x * x) % p; 
    }
    return res; 
}

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

    // sizes for each unique set
    vector<ll> sizes;
    auto all_sizes = dj.get_sizes();
    for(auto x : parents)
        sizes.push_back(all_sizes[x]); 

    ll modval = ll(1e9+7);
    // solving these just requires the right way
    // to solve these
    // during the contest i tried to count them in a more
    // difficult way.  sad that only counting prevented me
    // or maybe that is the whole point of the problem. SAD. idk. 
    
    // i tried to count the number of good paths directly
    // it is much easier to count the number of total paths
    // and the number of bad paths. why do these insights not come
    // to me?

    ll summ = 0;
    for(auto x : sizes)
        summ += x;
    if(summ != n)
        throw("something wacky is going on here!\n");

    ll count = mod_power(n, k, modval);
    for(auto x : sizes) {
        ll val = mod_power(x, k, modval);
        count = (count - val + modval) % modval;
    }
    printf("%lld\n", count);
        

    return 0;
}


