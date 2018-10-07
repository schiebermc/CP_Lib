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

/////////////// > HEAP SORT < ///////////////////////
class heap {
    public:
        ll n_;
        vector<ll> a_;
        
        heap(vector<ll>& a) {
            a_ = a;
            n_ = a_.size();
        }
        void heapify() {
            for(ll i=n_/2; i>=0; i--) {
                max_heap(i);
            }
        }
        void max_heap(ll i) {
            // apply the heap condition (max)

            ll largest;
            ll l = left(i);
            ll r = right(i);
            
            if(l < n_ and a_[l] > a_[i]) {
                largest = l;
            } else {
                largest = i;
            }
    
            if(r < n_ and a_[r] > a_[largest]) {
                largest = r;
            } 
    
            // if largest == i, do nothing
            // else, swap i with largest. then repeat
            // with largest to ensure heap condition at that level
            if(largest == i) {
                ;
            } else {
                swap(i, largest);
                max_heap(largest);
            }
        }
        void swap(ll i, ll j) {
            ll tmp = a_[i];
            a_[i] = a_[j];
            a_[j] = tmp;
        }
        ll left(ll i) { return 2*i;}
        ll right(ll i) { return 2*i+1;}
        ll parent(ll i) { return i/2;}
};


void heap_sort(vector<ll>& a) {
    // heapsort
    // time: O(nlogn)
    // space: O(1) !
    ll n = a.size();
    heap h(a);
    h.heapify();
    for(ll i=n-1; i>=0; i--) {
        a[i] = h.a_[0];
        h.n_ -= 1;
        h.a_[0] = h.a_[i];
        h.max_heap(0);
    }
}

/////////////// > MERGE SORT < ///////////////////////
void divide(vector<ll>& a, ll start, ll stop, vector<ll>& l, vector<ll>& r) {
    // stop is inclusive
    ll mid = (stop - start) / 2;
    for (ll i=start; i<=mid; i++) {
        l.push_back(a[i]);
    }
    for (ll i=mid+1; i<=stop; i++) {
        r.push_back(a[i]);
    }
}

void merge_sort(vector<ll>& a, ll start, ll stop){
    
    // base case (single value)
    if(start == stop)
        return; 

    // divide the array
    vector<ll> l;
    vector<ll> r;
    divide(a, start, stop, l, r);
    
    // conquer the subproblems
    merge_sort(l, 0, l.size()-1);
    merge_sort(r, 0, r.size()-1);

    // combine the subproblems
    ll lp = 0;
    ll rp = 0;
    for(ll i=start; i<=stop; i++) {
        if(rp == r.size() or (lp < l.size() and l[lp] < r[rp])) {
            a[i] = l[lp];
            lp++;
        } else {
            a[i] = r[rp];
            rp++;
        }
    }
}

/////////////// > BUBBLE SORT < ///////////////////////
void swap(vector<ll>& a, ll i, ll j) {
    ll tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void bubble_sort(vector<ll>& a) {
    // bubble sort
    // O(n^2)
    // simple N^2 scan containing many superflous comparisons
    // sorted from the front to the back
    for(ll i=0; i<a.size(); i++) {
        for(ll j=i+1; j<a.size(); j++) {
            if(a[i] > a[j]){
                swap(a, i, j);
            }
        }
    }
}

/////////////// > INSERTION SORT < ///////////////////////

void insertion_sort(vector<ll>& a) {
    // insertion sort
    // O(n^2)
    // simple N^2 scan containing superflous comparisons
    // sorted from the front to the back
    for(ll i=1; i<a.size(); i++) {
        ll j = i-1;
        ll val = a[i];
        while(j >= 0 and a[j] > val) {
            // move a[j] back
            // that's why we saved val
            a[j+1] = a[j]; 
            j--;
        }
        // insert a[i] where it belongs
        a[j+1] = val;
    }
}


void print_vector(string name, vector<ll>& a) {
    printf("%s\n", name.c_str());
    for(auto x : a) {
        printf("%lld ", x);
    }
    printf("\n");
}

int main() {

    // variables
    ll n;
    cin >> n;

    vector<ll> arr; arr.resize(n);
    for(ll i=0; i<n; i++) {
        scanf("%lld", &arr[i]);
    }
    
    print_vector("vector before sorting: ", arr);
    insertion_sort(arr);
    bubble_sort(arr);
    heap_sort(arr);
    merge_sort(arr, 0, arr.size()-1);
    print_vector("vector after  sorting: ", arr);
    
    return 0;
}

