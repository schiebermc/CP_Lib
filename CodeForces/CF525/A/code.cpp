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

int main() {
   
    int n, a, b, y;
    for(int n = 1; n < 101; n++) {
        if(n > 1) {
            for(int x = 1; x<= n; x++) {
                for(int y = 1; y <= x; y++) {
                    if(x%y == 0 and x*y > n and x / y < n){
                        a = x;
                        b = y;
                    }
                }
            }
            printf("%d %d\n", a, b);
        }
        else
            printf("-1\n");
    }
    return 0;
}

