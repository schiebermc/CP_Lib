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

ll closest(ll val, set<ll>& vec) {

    auto itr = vec.lower_bound(val);

    if(itr == vec.end()) { // all elements are less than val
        return *vec.rbegin(); // return last value 
    } 
    
    ll low, high;
    
    high = *itr;
    if(itr == vec.begin())
        return high;

    itr--;
    low = *itr;

    ll diff1 = abs(val - low);
    ll diff2 = abs(val - high);
    if(diff1 < diff2)
        return low;
    else
        return high;
}

ll closest_outer(float val, set<ll>& vec) {
    // have to test the floor and the ceil of val
    ll low = ll(floor(val));
    ll hig = ll(ceil(val));

    ll closest1 = closest(low, vec);
    ll closest2 = closest(hig, vec);

    float diff1 = abs(float(closest1) - val);
    float diff2 = abs(float(closest2) - val);

    if(diff1 < diff2)
        return closest1;
    else
        return closest2;

}

void validate() {
    printf("performing validaton\n");
    set<ll> vec;
    for(ll i=0; i<10; i++) {
        ll val = rand() % 10;
        vec.emplace(val);
    }
    for(auto val : vec)    
        printf("%lld, ", val);
    printf("\n");
    for(ll i = 0; i< 19; i++) {
        float val = float(rand() % 10) + 0.5;
        
        printf("closest element to %f is %lld\n", val, closest_outer(float(val), vec));
    }
}

int main() {

    ll n, m, cs, ce, v;
    cin >> n >> m >> cs >> ce >> v;

    set<ll> s; 
    set<ll> e; 
    
    ll d;
    for(ll i=0 ;i< cs; i++) {
        scanf("%lld ", &d);
        s.emplace(d);
    }
    for(ll i=0 ;i< ce; i++) {
        scanf("%lld ", &d);
        e.emplace(d);
    }

    ll q;
    cin >> q; 

    // n and m are on the order of 10^8, so any graph solution
    // is out of the question.

    float mid;
    ll best_e, best_s;
    ll x1, y1, x2, y2;
    ll etime, stime;
    for(ll i=0; i<q; i++) {      
  
        cin >> x1 >> y1 >> x2 >> y2;

        if(x1 == x2){
            printf("%lld\n", abs(y1 - y2));
            continue;
        }

        // the hotel is a freaking rectangle!!
        // otherwise, located the closest stair or elevator to the 
        // intersection of y1 and y2
        if(y1 > y2) 
            mid = float(y2) + float(y1 - y2) / 2.;
        else
            mid = float(y1) + float(y2 - y1) / 2.;
     
 
        // GOD DAMN THIS WAS ANNOYING
        if(cs != 0) {
            best_s = closest_outer(mid, s);
            stime = abs(x2 - x1) + abs(best_s - y1) + abs(best_s - y2); 
        }

        if(ce != 0) {
            best_e = closest_outer(mid, e);
            etime = ll(ceil(float(abs(x2 - x1)) / float(v))) + abs(best_e - y1) + abs(best_e - y2); 
        }
        //printf("(%lld, %lld), (%lld, %lld)\n", x1, y1, x2, y2);
        //printf("%f, %lld, %lld\n", mid, best_s, best_e);


        printf("%lld\n", min(etime, stime));
        
    }

    validate();
}




