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

int main() {

    // variables
    ll T, N;
    cin >> T;

    for(ll i=0; i<T; i++) {
        cin >> N;
        N--;
        ll count = pow(2, (N / 26));
        if(N%26 < 2) 
            printf("%lld 0 0\n", count);
        else if(N%26 < 10) 
            printf("0 %lld 0\n", count);
        else
            printf("0 0 %lld\n", count);
    }


    return 0;
}

