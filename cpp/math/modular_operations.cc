
ll mod_power(ll x,ll y,ll p){
    // computes x ^ y % p 
    ll res = 1;
    x = x % p;  
    while (y > 0) {
        if ((y & 1) == 1)  
            res = (res * x) % p ;
        y = y >> 1;
        x = (x * x) % p; 
    }
    return res; 
}


ll mod_subtraction(ll x, ll y, ll modval){
    // you have to add modval because neg numbers
    // are possible.  adding maintins equivalance class
    return (x - y + modval) % modval;  
}

