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
 
    ll n, m;
    char val;
    cin >> n >> m;
    
    vector<vector<bool>> grid; grid.resize(n);
    for(ll i=0; i<n; i++){
        grid[i].resize(m);
        for(ll j=0; j<m; j++){
            cin >> val; //scanf("%c", &val);
            grid[i][j] = val == '*';
        }

    }  

    vector<tuple<ll, ll, ll>> stars;
    ll size, score;
    
    for(ll row=0; row<n; row++){
        for(ll col=0; col<m; col++){
            if(grid[row][col]){
                size = 1;
                while(true){
                    score = 0;
                    score += ll(col+size <  m and grid[row][col+size]); 
                    score += ll(col-size >= 0 and grid[row][col-size]);
                    score += ll(row+size <  n and grid[row+size][col]);
                    score += ll(row-size >= 0 and grid[row-size][col]);
                    if(score < 4){
                        if(size != 1)
                            stars.push_back(make_tuple(row, col, size-1));
                        break;
                    }
                    size += 1;
                }
            }
        }
    }

    ll row, col,  ind;
    for(auto star : stars){
        row = get<0>(star);
        col = get<1>(star);
        size = get<2>(star);
        ind = 0;
        while(ind <= size){
            grid[row+ind][col] = false; 
            grid[row-ind][col] = false;
            grid[row][col+ind] = false;
            grid[row][col-ind] = false;
            ind += 1;
        }
    }
    
    ll count = 0;
    for(ll row=0; row<n; row++)
        for(ll col=0; col<m; col++)
            count += (int)grid[row][col];
        
    if(count == 0){
        printf("%lu\n", stars.size()); 
        for(auto star : stars){
            row = get<0>(star)+1;
            col = get<1>(star)+1;
            size = get<2>(star);
            printf("%lld %lld %lld\n", row, col, size);
        }
    } else {
        printf("-1\n");
    }
    return 0;
}
