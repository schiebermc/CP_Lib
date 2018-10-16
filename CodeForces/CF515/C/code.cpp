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


void solution(ll q){

    string query;
    bool placed = false;
    ll lind = 0;
    ll rind = 0;
    map<ll, ll> book_map;
    //map<ll, ll> bookshelf;
    for (ll i=0; i<q+1; i++) {
        
        getline(cin, query);
        ll book_ind = ((ll)query[2]) - 48;  
        printf("%lld\n", book_ind);
        //printf("%s\n", query.c_str()); 
        if(query[0] == 'R'){
            book_map[book_ind] = rind;
            rind++;
            if(!placed){
                placed = true;
                lind--;
            }
        } else if(query[0] == 'L'){
            book_map[book_ind] = lind;
            lind--;
            if(!placed){
                placed = true;
                rind++;
            }
        } else if(query[0] == '?'){
            for(auto kv : book_map) 
                printf("(%lld, %lld)\n", kv.first, kv.second);
            printf("\n");
            //printf("%lld\n", book_ind);
            ll ldist = book_map[book_ind] - lind;
            ll rdist =  rind - book_map[book_ind];
            printf("%lld, %lld\n", ldist, rdist);
            //printf("%lld\n", min(book_map[book_ind] - lind, rind - book_map[book_ind])-1);
        }
    }

}

int main() {

    // variables
    ll q;
    cin >> q;
    solution(q);
    
    return 0;
}

