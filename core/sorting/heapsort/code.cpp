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
void print_vector(string name, vector<ll>& a);
void heap_sort(vector<ll>& a);

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

void solution(vector<ll>& a){
    heap_sort(a);
}

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
    solution(arr);
    print_vector("vector after  sorting: ", arr);
    
    return 0;
}

