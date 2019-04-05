//#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 

using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;

ll solution4(ll N, ll K, vector<ll>& A){

    // using prefix arrays and binary search

    ll count = 0;
    ll max_A = *max_element(A.begin(), A.end());

    vector<vector<ll>> c(N); for(ll i=0; i<N; i++) {c[i].resize(max_A);}
    vector<vector<ll>> f(N); for(ll i=0; i<N; i++) {f[i].resize(max_A);}
    for(ll r=A[0]-1; r<max_A; r++) 
        c[0][r] += 1;

    ll val;
    for(ll l=1; l<N; l++){
        val = A[l]-1;
        for(ll r=0; r<max_A; r++)
            c[l][r] = c[l-1][r];
        for(ll r=val; r<max_A; r++)
            c[l][r]++;
    }
    
    f[0][A[0]-1]++;
    for(ll l=1; l<N; l++){
        for(ll r=0; r<max_A; r++)
            f[l][r] = f[l-1][r];
        f[l][A[l]-1]++; 
    }

    ll X, M, F, R, L, m, l, r, v, size, val1, val2;

    X = max_A / 2;
    for(size=1; size<N+1; size++){
        m = ceil(double(K)/double(size));
        for(l=0; l<N-size+1; l++){
            
            r = l + size - 1;
            L = 0;
            R = max_A-1;
            M = X;
 
            if(l == 0){
                if(M != 0)
                    val1 = (c[r][M-1])*m;
                else
                    val1 = 0;
                val2 = (c[r][M])*m; 
            } else {
                if(M != 0)
                    val1 = (c[r][M-1]-c[l-1][M-1])*m; 
                else
                    val1 = 0;
                val2 = (c[r][M]-c[l-1][M])*m;
            }

            while(not (val1 < K and val2 >= K)){

                if(val1 < K and val2 < K)
                    L = M+1;
                else
                    R = M-1;
                M = L + ((R - L) / 2);
                
                if(l == 0){
                    if(M != 0)  
                        val1 = (c[r][M-1])*m;
                    else
                        val1 = 0;
                    val2 = (c[r][M])*m; 
                } else {
                    if(M != 0)
                        val1 = (c[r][M-1]-c[l-1][M-1])*m; 
                    else
                        val1 = 0;
                    val2 = (c[r][M]-c[l-1][M])*m; 
                }
            }
            X = M;

            F = f[r][X];
            if(l != 0)
                F -= f[l-1][X];          
            
            if(F == 0)
                continue;
            if(F > max_A)
                continue;
            
            v = f[r][F-1];
            if(l != 0)
                v -= f[l-1][F-1];            
            
            if(v > 0){
                count++; 
            }
        }
    }

    return count;
}

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

    OrderStatisticTree(ll max_n) : tree_(max_n+1) {
        // the range will be from 0 to max_n
        max_n_ = max_n;
    }
    OrderStatisticTree(ll max_n, vector<ll> &a) : tree_(max_n+1) {
        // the range will be from 0 to max_n
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
};


ll solution5(ll N, ll K, vector<ll>& A){

    // using order statistic tree
    ll count = 0;
    ll max_A = *max_element(A.begin(), A.end());
    OrderStatisticTree Otree(max_A);
    for(ll l=0; l<N; l++) {
        for(ll r=l; r<N; r++) {
            ll size = r - l + 1;
            ll m = ceil(double(K)/double(size));
            Otree.add_val(A[r]);
            ll rank = ceil(double(K)/double(m));
            ll X = Otree.kthsmallest(rank);
            ll F = Otree.rank(X) - Otree.rank(X-1);
            if(F == 0 or F > max_A)      
                continue;
            ll c = Otree.rank(F) - Otree.rank(F-1);
            if(c != 0){
                count++;
            }
        }
        for(ll r=l; r<N; r++) {
            Otree.delete_val(A[r]);
        }
    }

    return count;
}


ll solution6(ll N, ll K, vector<ll>& A){

    // using policy based data structure
    typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> order_set; 
    order_set s;

    // s.insert(val)
    // s.find_by_order(rank)
    // s.order_of_key(val)
    // s.clear()

    ll count = 0;
    for(ll l=0; l<N; l++) {
        for(ll r=l; r<N; r++) {
            ll size = r - l + 1;
            ll m = ceil(double(K)/double(size));
            s.insert(A[r]);
            ll rank = ceil(double(K)/double(m));
            ll X = s.find_by_order(rank);
            ll F = s.order_of_key(X) - s.order_of_key(X-1);
            if(F == 0 or F > max_A)      
                continue;
            ll c = s.order_of_key(F) - s.order_of_key(F-1);
            if(c != 0){
                count++;
            }
        }
        s.clear()
    }

    return count;
}

void validate() {
    ll N_max = 5;
    ll A_max = 5;

    ll N, K;
    for(ll seed=86; seed<87; seed++){
        srand(seed);
        N = rand() % N_max + 1;
        K = rand() % ll(1e9) + 1;
        
        //printf("%lld %lld\n", N, K); 
        vector<ll> A; A.resize(N);
        for(ll i=0; i<N; i++)
            A[i] = rand() % A_max + 1;
        
        ll val1 = solution4(N, K, A);
        ll val2 = solution5(N, K, A);
        if(val1 != val2){
            printf("failed at seed: %lld -- %lld vs %lld\n", seed, val1, val2);
       
            for(auto x : A)
                printf("%lld ", x);
            printf("\n");
            
        
        }
        //printf("%lld - %lld\n", solution4(N, K, A), solution5(N, K, A));
    }

}

int main() {    

    validate();

    ll t;
    cin >> t;
    ll N, K;
    for(ll test=0; test<t; test++){
        
        cin >> N >> K;
        vector<ll> A; A.resize(N);
        for(ll i=0; i<N; i++)
            scanf("%lld", &A[i]);
        
//        printf("%lld\n", solution4(N, K, A));
        printf("%lld\n", solution5(N, K, A));
        printf("%lld\n", solution6(N, K, A));
    }
        
return 0;
}

