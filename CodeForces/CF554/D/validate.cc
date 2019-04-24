void validation(ll start_seed, ll end_seed, ll n) {

    for(ll s=start_seed; s<=end_seed; s++) {
        srand(s);
        vector<ll> a;
        for(ll i=0; i<n; i++) {
            a.push_back(rand()%16);
        }
        //for (auto x : a) {
        //    printf("%lld, ", x);
        //}
        //printf("\n");
        //if(solution2(n, a) != solution(n, a)) {
        //    printf("failed at seed: %lld\n", s);
        //}

    }

}

