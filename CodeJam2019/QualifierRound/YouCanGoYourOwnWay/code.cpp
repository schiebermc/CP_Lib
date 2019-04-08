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

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long int ll;

void advance_position(vector<ll> &position, char move, ll shift) {
    if(move == 'E')
        position[1] += shift;
    else
        position[0] += shift;
}

bool get_path(vector<char> &my_path, vector<char> &lydias_path, 
            vector<ll> lydias_position, vector<ll> my_position, ll step, ll N, ll& counter) {
     
    counter++;
    if(step == lydias_path.size())
        return true; 
    auto x = lydias_path[step];

    set<char> pos = {'E', 'S'};
    if(lydias_position == my_position) {
        pos.erase(x);
    }

    if(my_position[0] == N-1)
        pos.erase('S');
    if(my_position[1] == N-1)
        pos.erase('E');

// the secret sauce is here.
// as long as we are on the opposite side of the midline, 
// it's impossible to make an identical move, therefore
// a solution exists within oen offset of the diagonal
    if(my_position[0] > my_position[1])
        pos.erase('S');
    if(my_position[1] > my_position[0])
        pos.erase('E');
        
    advance_position(lydias_position, x, 1);
   
    vector<ll> pos2 = {};
    copy(pos.begin(), pos.end(), back_inserter(pos2));
    random_shuffle(pos2.begin(), pos2.end());     
    
    bool good = false;
    for(auto move : pos2) {
        
        advance_position(my_position, move, 1);
        good = get_path(my_path, lydias_path, lydias_position, my_position, step+1, N, counter);            
        
        if(good) {
            my_path[step] = move;
            break;
        } 
        
        advance_position(my_position, move, -1);
    }
   
    return good;

}

void validation(ll start_seed, ll end_seed, ll n) {

    ll counter = 0;        
    vector<char> moves = {'E', 'S'}; 
    for(ll s=start_seed; s<=end_seed; s++) {
        srand(s);
        ll size = 2*n - 2;
        vector<char> a; a.resize(size); 
        vector<ll> pos = {0, 0};

        for(ll i=0; i<size; i++) {

            if(pos[0] == n-1)
                a[i] = 'E';
            else if(pos[1] == n-1)
                a[i] = 'S';
            else { 
                char move = moves[rand()%2];
                a[i] = move;

            }
            advance_position(pos, a[i], 1);
        
        }
        //for (auto x : a) {
        //    printf("%c ", x);
        //}
        //printf("\n");
        vector<char> my_path; my_path.resize(size);
        get_path(my_path, a, {0, 0}, {0, 0}, 0, n, counter);

    }
    printf("that took %lld iterations\n\n", counter);

}

int main() {

    IOS;
   
//    validation(0, 100, 1000);
    ll T, N;
    cin >> T;
    for(ll test=0; test<T; test++) {

        cin >> N;
        ll size = 2*N-2;
        vector<char> lydias_path; lydias_path.resize(size);
        for(ll i=0; i<size; i++) {
            cin >> lydias_path[i];
        }

        ll counter = 0;        
        vector<char> my_path; my_path.resize(size);
        get_path(my_path, lydias_path, {0, 0}, {0, 0}, 0, N, counter);

//        printf("that took %lld iterations\n", counter);
        printf("Case #%lld: ", test+1);
        for(auto x : my_path)
            printf("%c", x);
        printf("\n");

    } 

    return 0;
}



