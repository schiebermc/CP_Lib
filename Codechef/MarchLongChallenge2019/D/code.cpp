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

using namespace std;

typedef long long int ll;

ll solution4(ll N, ll K, vector<ll>& A){

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
            
            if(v > 0)
                count++; 
        }
    }

    return count;
}

void validate() {
    ll N_max = 5;
    ll A_max = 5;

    ll N, K;
    for(ll seed=0; seed<100; seed++){
        N = rand() % N_max + 1;
        K = rand() % ll(1e9) + 1;
        
        printf("%lld %lld\n", N, K); 
        vector<ll> A; A.resize(N);
        for(ll i=0; i<N; i++)
            A[i] = rand() % A_max + 1;
       
        for(auto x : A)
            printf("%lld ", x);
        printf("\n");
        //printf("%lld\n", solution4(N, K, A));
        //printf("%lld\n", solution4(N, K, A));
    }

}

int main() {    

//    validate();

    ll t;
    cin >> t;
    ll N, K;
    for(ll test=0; test<t; test++){
        
        cin >> N >> K;
        vector<ll> A; A.resize(N);
        for(ll i=0; i<N; i++)
            scanf("%lld", &A[i]);
        
        printf("%lld\n", solution4(N, K, A));
    }
        
return 0;
}

