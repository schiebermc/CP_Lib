
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

ll closest_to_float(float val, set<ll>& vec) {
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



