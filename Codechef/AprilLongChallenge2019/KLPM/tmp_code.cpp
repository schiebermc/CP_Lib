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

ll is_palindrome(string s) {
    for(int i=0, j=s.size()-1; i<s.size()/2; i++, j--) 
        if(s[i] != s[j])
            return 0;
    return 1;
}

ll brute_force(string S) {
    string s1, s2;
    ll count = 0;
    ll N = S.size();
    for(ll i=0; i<N; i++) {
        for(ll j=i; j<N; j++) {
            for(ll k=j+1; k<N; k++) {
                for(ll l=k; l<N; l++) {
                    ll size1 = j-i+1;
                    ll size2 = l-k+1;
                    s1 = S.substr(i, size1);                
                    s2 = S.substr(k, size2);                
                    count += is_palindrome(s1+s2);   
                }
            }
        }
    }
    return count;
}
  
ll solution1(string S) {
    ll N = S.size();
    unordered_map<char, set<ll>> positions;
    for(ll i=0; i<N; i++) {
        if(positions.find(S[i]) == positions.end())
            positions[S[i]] = {};
        positions[S[i]].emplace(i);
    }
//    for(auto x : positions) {
//        printf("%c: ", x.first);
//        for(auto m : x.second)
//            printf("%lld ", m);
//        printf("\n");
//    }

    // all answers are in the form of s1 + x + s2
    // scan all substrings
    // collect viable s2 matches using map above. what does this look like?
    //   viable s2 are a vector of vectors.  the outermost layer is all viable s2
    //   the innermost vector is 

    string s1;
    vector<vector<int>> pr(N);
    for(int i=0; i<N; i++) {pr[i] = vector<int>(N);}
    for(ll i=0; i<N; i++) {
        s1 = "";
        for(ll j=i; j<N; j++) {
            s1 += S[j];
            pr[i][j] = is_palindrome(s1);
        }
    }
//    for(ll i=0; i<N; i++) {
//        for(ll j=i; j<N; j++) {
//            printf("(%lld, %lld) %lld\n", i, j, pr[i][j]);
//        }
//    }

    ll count = 0;
    set<ll> matches;
    set<ll> next_matches;
    for(ll i=0; i<N; i++) {
        s1 = "";
        for(ll j=i; j<N; j++) {
            s1 += S[j];
//            printf("s1: %s\n", s1.c_str());
            next_matches = {};
            if(j==i){
                for(auto x : positions[S[j]])
                    if(x > j)
                        next_matches.emplace(x);
            } else {
                for(auto index : matches ) {
                    if(positions[S[j]].find(index-1) != positions[S[j]].end() and index -1 > j)
                        next_matches.emplace(index-1);
                }
            }
            matches = next_matches;
            if(matches.size() == 0)
                break;
            for(auto x : matches) {
                count++; // s1 + s2
                // span forwards.
                for(ll k=j+1; k<x; k++)
                    count += pr[j+1][k];
                // span forwards.
                for(ll k=x-1; k>j; k--)
                    count += pr[k][x-1];
            }
//            printf("matches: ");
//            for(auto x : matches)
//                printf("%lld ", x);
//            printf("\n");
//            printf("count: %lld\n", count);
        }
    }
return count;
}

void validate(ll start_seed, ll end_seed, ll maxN) {
    clock_t t0, T0 = 0, T1 = 0;
    for(ll s=start_seed; s<=end_seed; s++) {
        srand(s);
        ll N = rand() %maxN+1;
        string S;
        for(ll i=0; i<N; i++) {
            S += 'a' + rand()%1;  // restricted letters to produce more palys
        }
        t0 = clock();
        ll val1 = 1;//brute_force(S);
        T0 += clock() - t0;
        t0 = clock();
        ll val2 = solution1(S);
        T1 += clock() - t0;
        printf("%lld\n", val1 -val2);
    }

    printf("(%f, %f)\n", float(T0)/CLOCKS_PER_SEC, float(T1)/CLOCKS_PER_SEC);
}

int main() {

    string S;
    cin >> S;
    printf("%lld\n", solution1(S));
//    printf("%lld\n", brute_force(S));
//    validate(0, 5, 500);

    return 0;
}

