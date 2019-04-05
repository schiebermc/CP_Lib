
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

typedef long long int ll;

// order statistic tree
// four operations: insert, delete, findkthsmallest(k), rank(x)
// https://www.geeksforgeeks.org/order-statistic-tree-using-fenwick-tree-bit/

class FenwickTree {
private:
    ll n_;
    vector<ll> tree_;    
public:
    FenwickTree(ll n) {
        n_ = n;
        tree_ = vector<ll>(n+1, 0);
    }
    void update(ll ind, ll val) {
        ind++;
        while(ind <= n_) {
            tree_[ind] += val;
            ind = ind + (ind & (-ind));
        }
    }    
    ll get_sum(ll ind) {
        ind++;
        ll summ = 0;
        while(ind > 0 ) {
            summ += tree_[ind];
            ind = ind - (ind & (-ind));
        }
        return summ;
    }
};

class OrderStatisticTree {

private:
    ll max_n_;
    FenwickTree tree_;

public:

    OrderStatisticTree(ll max_n, vector<ll> &a) : tree_(max_n+1) {
        // the range will be from 0 to max_n, inclusive [0, max_n]
        max_n_ = max_n;
        for(auto x : a)
            add_val(x);
    }
    void add_val(ll val) {
        tree_.update(val, 1);
    }
    void delete_val(ll val) {
        tree_.update(val, -1);
    }
    ll rank(ll val) {
        return tree_.get_sum(val);
    }
    ll kthsmallest(ll k) {
        ll L = 0;
        ll R = max_n_;
        while(L < R) {
            ll M = (L + R) / 2;
            if(k <= tree_.get_sum(M))
                R = M;
            else
                L = M + 1;
        }
        return L;
    }
    ll frequency(ll val) {
        if(val == 0)
            return rank(val)
        else
            return rank(val) - rank(val-1);
    }
};

int main() {

    vector<ll> a = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};

    OrderStatisticTree t(9, a);
    for(ll i=0; i<=9; i++) {
        printf("number: %lld, rank: %lld\n", i, t.rank(i));
    }    
    for(ll i=0 ;i<12; i++) {
        printf("rank: %lld, number: %lld\n", i, t.kthsmallest(i));
    }

return 0;
}
