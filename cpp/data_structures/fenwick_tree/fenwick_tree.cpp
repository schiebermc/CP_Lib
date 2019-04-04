
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

typedef long long int ll;

// binary indexed tree (BIT) or fenwick tree
// allows prefix sums to be calculated efficiently
// can only do cumulative (prefix) operations.
// segment tree can do more, but:
// uses half the memory (no internal nodes) 
// slightly faster prefactor
// easier to implement 

// we could have prefix arrays. but updating them requires O(n) time


class FenwickTree {
//ref: https://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/

private:

    ll n_;
    vector<ll> tree_;    

public:
    
    FenwickTree(ll n, vector<ll>& a) {
        n_ = n;
        tree_ = vector<ll>(n+1, 0);
        for(ll ind=0; ind<n; ind++)
            update(ind, a[ind]);
    }

    void update(ll ind, ll val) {
        // ind is 0-based. val should be a shift!!
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

ll brute_force(ll i, ll j, vector<ll> &a) {
    ll summ = 0;
    for(ll x=i; x<=j; x++)
        summ += a[x];
    return summ;
}

int main() {

    vector<ll> a = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    FenwickTree t(12, a);

    for(ll i=0; i<12; i++) 
        printf("%lld, %lld\n", brute_force(0, i, a), t.get_sum(i));
 
    printf("sum1: %lld\n", t.get_sum(5));
    t.update(3, 6);
    printf("sum2: %lld\n", t.get_sum(5));


return 0;
}
