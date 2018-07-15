//#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <set>

using namespace std;

typedef long long int ll;

void solution(ll n, ll m){

    ll j, k, x;
    ll best = 0;
    vector<vector<ll>> segs;
    
    for(ll i=0; i<m; i++) {

        scanf("%lld %lld %lld", &j, &k, &x);
        ll current_size = segs.size();
        ll val;
        
        if(current_size == 0) {
            segs.push_back({j, k, x});
            continue;
        }
       
        for(ll M=0; M<current_size; M++) {
            
            vector<ll> seg = segs[M];

            if(j < seg[0] and k > seg[1]) {

                segs.push_back({j, seg[0]-1, x});        
                segs.push_back({seg[0], seg[1], seg[2] + x});        
                segs.push_back({seg[1]+1, k, x});        
                val = seg[2] + x;
    
            } else if(j < seg[0]) {
                if(k < seg[0]) {
                
                    segs.push_back({j, k, x});
                    val = x;
                
                } else {
                    
                    segs.push_back({j, seg[0]-1, x});
                    segs.push_back({seg[0], k, seg[2] + x});
                    val = seg[2] + x;
                
                }
            } else if(k > seg[1]) {
                if(j > seg[1]) {
                
                    segs.push_back({j, k, x});
                    val = x;
                
                } else {

                    segs.push_back({j, seg[1], seg[2] + x});        
                    segs.push_back({seg[1]+1, k, x});        
                    val = seg[2] + x;

                }
            } else {

                segs.push_back({j, k, seg[2] + x});        
                val = seg[2] + x;

            }
            best = (best < val ? val : best);
        }
        
    }
    
    printf("%lld\n", best);

}

void swap(ll i, ll j, vector<ll>& a) {
    ll tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

int main() {

    // variables
    ll n, m;
    cin >> n >> m;
    solution(n, m);
    
    return 0;
}

