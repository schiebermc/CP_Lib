//#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <set>
#include <climits>

using namespace std;

typedef long long int ll;

ll best_from_here(string& a, string& b, ll i, ll j, unsigned long na, unsigned long nb, map<pair<ll, ll>, ll>& saved);

void solution(string a, string b){
    map<pair<ll, ll>, ll> saved;
    ll count = best_from_here(a, b, (ll)a.size(), (ll)b.size(), a.size(), b.size(), saved);
    printf("%lld\n", count);

}

ll best_from_here(string& a, string& b, ll i, ll j, unsigned long na, unsigned long nb, map<pair<ll, ll>, ll>& saved){

    if(saved.find(make_pair(i, j)) != saved.end())
        return saved[make_pair(i, j)];

    if(i == -1 or j == -1)
        return 0;   

    ll count1 = 0;
    ll count2 = 0;
    ll count3 = 0;
    if(a[i] == b[j])
        count1 = 1 + best_from_here(a, b, i-1, j-1, na, nb, saved);

    else
        count2 = best_from_here(a, b, i-1, j, na, nb, saved);
        count3 = best_from_here(a, b, i, j-1, na, nb, saved);
   
     
    ll ans = max(max(count1, count2), count3);
    saved[make_pair(i, j)] = ans;
    return ans;

}

int main() {

    // variables
    string n, m;
    cin >> n;
    cin >> m;

    solution(n, m);
    
    return 0;
}

