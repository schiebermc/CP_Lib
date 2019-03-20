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


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll N;
    cin >> N;
    vector<string> S; 
    string s;

    vector<int> counts(N);

    for(ll i=0; i<N; i++){
        cin >> s;
        S.push_back(s);
    } 

    ll prev = ll(S[0][0]); 
//    string W = "";
    bool done = false;
    ll j, b;

    ll width = 1;
    vector<bool> neighbors(width*2 + 1);

    while(not done) { 
        done = true;
        for(ll i=0; i<N; i++){

            for(ll m=i-width, c=0; m<i+width+1; m++, c++)
                neighbors[c] = S[m%N].size() != counts[m%N] and m%N != b;

            j = 10, b = i;
            for(ll m=i-width, c=0; m<i+width+1; m++, c++){
                if(neighbors[c] and abs(ll(S[m%N][counts[m%N]]) - prev) < j){
                    j = abs(ll(S[m%N][counts[m%N]]) - prev);
                    b = m%N;   
                } 
            }

//            if(S[b].size() != counts[b]){
//                printf("%lld ", b+1);
////                W += S[b][counts[b]];
//                prev = ll(S[b][counts[b]]);
//                counts[b]++;
//            }
            
            if(S[i].size() != counts[i]){
                printf("%lld ", i+1);
                counts[i]++;
                done = false;
            }

        }
    }
    printf("\n"); 
    
//    ll score = 0;
//    for(ll i=1; i<W.size(); i++){
//        score += abs(ll(W[i]) - ll(W[i-1]));
//    }
//
//    printf("%s - %lld\n", W.c_str(), score);
    
    return 0;
}

