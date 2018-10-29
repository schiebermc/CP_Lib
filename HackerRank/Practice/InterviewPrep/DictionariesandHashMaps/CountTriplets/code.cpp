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


ll solution1(ll n, ll r, vector<ll> a){
    ll count = 0;
    for(ll i=0; i<n; i++) {
        for(ll j=i+1; j<n; j++) {
            for(ll k=j+1; k<n; k++) {
                if(a[i]*r == a[j] and a[j]*r == a[k])
                    count++;
            }
        }
    }    
    return count;
}

ll solution2(ll n, ll r, vector<ll> a){
    ll count = 0;
    for(ll i=0; i<n; i++) {
        for(ll j=i+1; j<n; j++) {
            if(a[i]*r != a[j]) {continue;}
            for(ll k=j+1; k<n; k++) {
                if(a[j]*r == a[k])
                    count++;
            }
        }
    }    
    return count;
}

ll solution3(ll n, ll r, vector<ll> a){
    // pump everything into a map O(n)
    map<ll, vector<ll>> stuff;
    for(ll i=0; i<n; i++) {
        if(stuff.find(a[i]) ==  stuff.end()) 
            stuff[a[i]] = {i};
        else
            stuff[a[i]].push_back(i);
    }
    
    ll count = 0;
    for(auto &kv : stuff) {
        ll val = kv.first;
        if(stuff.find(val*r) == stuff.end() or stuff.find(val*r*r) == stuff.end()) {
            continue;
        } else {
            vector<ll>& vec1 = kv.second;
            vector<ll>& vec2 = stuff[val*r];
            vector<ll>& vec3 = stuff[val*r*r];
            
            ll ind1 = 0;
            ll ind2 = 0;
            ll ind3 = 0;
            while(vec2[ind2] <= vec1[ind1]) {ind2++;}
            while(vec3[ind3] <= vec2[ind2]) {ind3++;}
        
            for(ll i1 = ind1; i1<vec1.size(); i1++) {
                ll x1 = vec1[i1];
                for(ll i2 = ind2; i2<vec2.size(); i2++) {
                    ll x2 = vec2[i2];
                    if(x1 >= x2) { continue; }
                    for(ll i3 = ind3; i3<vec3.size(); i3++) {
                        ll x3 = vec3[i3];
                        if(x2 < x3)
                            count++;
                        //if(x2 < x3)
                        //    count++;
                        //else 
                        //    break;
                    }
                }
            }
        }
    } 
    return count;
}

ll solution4(ll n, ll r, vector<ll> a){
    // pump everything into a map O(n)
    ll count = 0;
    map<ll, vector<ll>> stuff;
    for(ll i=0; i<n; i++) {
        if(stuff.find(a[i]/r) != stuff.end() and a[i] == (a[i]/r*r) and
           stuff.find(a[i]/r/r) != stuff.end() and a[i]/r/r*r == a[i]/r) {
            //printf("%lld, %lld, %lld\n", a[i]/r/r, a[i]/r, a[i]);        
            vector<ll> vec2 = stuff[a[i]/r];
            vector<ll> vec1 = stuff[a[i]/r/r];
            
            ll n1 = vec1.size();
            ll n2 = vec2.size();
            ll ind1 = 0;
            ll ind2 = 0;
            while(ind1 < n1 and ind2 < n2) {
                if(vec1[ind1] < vec2[ind2]){
                    count += (n2 - ind2);
                    ind1++;
                } else {
                    ind2++;
                }
            }
        }
        
        if(stuff.find(a[i]) ==  stuff.end()) 
            stuff[a[i]] = {i};
        else
            stuff[a[i]].push_back(i);
        
    
    }
    return count;
}

void validation(ll start_seed, ll end_seed, ll n) {

    clock_t t0;
    double T0 = 0.0;
    double T1 = 0.0;
    for(ll s=start_seed; s<=end_seed; s++) {
        srand(s);
        vector<ll> a;
        for(ll i=0; i<n; i++) {
            a.push_back(rand()%100);
            while(a[i] == 0)
                a[i] = rand()%100;
        }
        
        t0 = clock();
        ll val1 = 0;//solution3(n, 2, a);
        T0 += double( clock() - t0 ) / (double)CLOCKS_PER_SEC;
        t0 = clock();
        ll val2 = solution4(n, 2, a);
        T1 += double( clock() - t0 ) / (double)CLOCKS_PER_SEC;

        if(val1 != val2) {
            printf("failed at seed: %lld -- %lld !=  %lld\n", s, val1, val2);
        }

    }

    printf("T0: %f\n", T0);
    printf("T1: %f\n", T1);
}

int main() {

    // variables
    ll n, m;
    cin >> n >> m;

    vector<ll> arr; arr.resize(n);
    for(ll i=0; i<n; i++) {
        scanf("%lld", &arr[i]);
    }
    
    //validation(0, 10, 100000);
    ll ans = solution4(n, m, arr);

    printf("%lld\n", ans);
    return 0;
}

