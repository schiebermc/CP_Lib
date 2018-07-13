//#include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

typedef long long int ll;

class SegmentTree {
    
    // this class was constructed with inspiration and guidance from:
    // https://leetcode.com/articles/a-recursive-approach-to-segment-trees-range-sum-queries-lazy-propagation/
    // O(n) leaves, O(n-1) internal nodes.
    // build:  O(n) :D
    // update: O(k), where k = height of tree :D
    // query:  O(k), where k = height of tree :D

public:
    
    ll n_;
    vector<ll> tree_;
    ll max_depth_;
    vector<string> merge_op_;    

    SegmentTree(vector<ll>& data, vector<string> merge_op) 
    { 
        // allocate tree
        n_ = data.size();
        tree_.resize(4*n_); // conservative (should only require 2n)
        max_depth_ = ceil(log2(n_));         
        merge_op_ = merge_op;

        // insert leaf nodes in tree
        for (ll i=0; i<n_; i++)    
            tree_[n_+i] = data[i];
         
        // build the tree by calculating parents
        for (ll i = n_ - 1; i > 0; --i)
            tree_[i] = merge(tree_[i<<1], tree_[i<<1 | 1], log2(i));    
    }
     
    // update a tree node
    void update(ll ind, ll val) 
    { 
        // set value at position ind
        ind += n_;
        tree_[ind] = val;
         
        // move upward and update parents
        for (ll i=ind; i > 1; i >>= 1)
            tree_[i>>1] = merge(tree_[i], tree_[i^1], log2(i>>1));
    }
     
    // query interval [l, r)
    ll query(ll l, ll r) 
    {
        // FIXME future use? 
        ll res = 0;
        for (l += n_, r += n_; l < r; l >>= 1, r >>= 1)
        {
            if (l&1) 
                res += tree_[l++];
            if (r&1) 
                res += tree_[--r];
        }
        return res;
    }

private:
    
    ll merge(ll val1, ll val2, ll d){
        if(merge_op_.size() > 1)
            return simple_merge(val1, val2, merge_op_[(max_depth_ - 1- d) % merge_op_.size()]);
        else
            return simple_merge(val1, val2, merge_op_[0]);
    }

    ll simple_merge(ll val1, ll val2, string op){
        if(op == "+")
            return val1 + val2;
        else if(op == "OR")
            return val1 | val2;
        else if(op == "XOR")
            return val1 ^ val2;
        else if(op == "*")
            return val1 * val2;
        else if(op == "-")
            return val1 - val2;
        else
            throw;
    } 

};

void solution(ll n, ll m, vector<ll> a){

    ll N = pow(2, n);
    SegmentTree st(a, {"OR", "XOR"});

    ll p, b;
    for(ll q = 0; q<m; q++) {
        scanf("%lld %lld", &p, &b);
        st.update(p-1, b);
        //printf("yeah.....\n");
        //printf("%lld\n", st.query(0, 2));
        //printf("%lld\n", st.query(2, 4));
        printf("%lld\n", st.query(0, N));
    }

}

int main() {

    // variables
    ll n, m;
    cin >> n >> m;

    vector<ll> arr; arr.resize(pow(2, n));
    for(ll i=0; i<pow(2, n); i++) {
        scanf("%lld", &arr[i]);
    }
    
    //validation()
    solution(n, m, arr);
    
    return 0;
}

