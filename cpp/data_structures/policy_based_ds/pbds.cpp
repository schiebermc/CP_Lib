//#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 

typedef long long int ll;

using namespace std;
using namespace __gnu_pbds;

// pbds can add/remove elements, 
// find the number of elements less than x,
// find kth smallest element in O(log(n)) time
// moreover, it can be indexed like a sorted array
// https://goo.gl/WVDL6g
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> order_set; 

int main() {

    order_set s;
    // s.insert(val)
    // s.find_by_order(rank)
    // s.order_of_key(val)
    // s.clear()

     
    return 0;
}


