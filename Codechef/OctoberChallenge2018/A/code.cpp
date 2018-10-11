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
    ll T, K, P1, P2;
    cin >> T;

    for(ll i=0; i<T; i++) {
        cin >> P1 >> P2 >> K;
        ll div = (P1 + P2) / K;
        if(div%2 == 0)
            printf("CHEF\n");
        else
            printf("COOK\n");
    }


    return 0;
}

