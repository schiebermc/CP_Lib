//#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <set>

using namespace std;

typedef long long int ll;


//ll solution1(ll n, vector<ll> a){
//
//    ll sum1 = 0;
//    ll sum2 = 0;
//    ll sum3 = 0;
//    for(auto x : a) {
//        sum1 += x;
//    }
//
//    if(sum1 == sum3) {
//        printf("%lld\n", sum1);
//        return sum1;
//    }
//
//    ll tmp;
//    ll best = 0;
//    for(ll i=n-1; i>=0; i--) {
//
//        sum3 += a[i];
//        sum1 -= a[i];
//        tmp = sum1;
//        sum2 = 0;
//            
//        if(sum1 == sum3) {
//            best = (sum1 > best ? sum1 : best);
//        }
//
//        //if(sum1 < sum3) {
//        //    printf("%lld\n", best);
//        //    return;
//        //}
//        
//        for(ll j=i-1; j>=0; j--) {
//            
//            tmp -= a[j];
//            sum2 += a[j];
//
//            if(tmp < sum3){
//                break;
//            }         
//   
//            if(tmp == sum3) {
//                best = (tmp > best ? tmp : best);
//            }
//        
//        }
//
//    }
//
//    printf("%lld\n", best);
//    return best;
//}

ll solution2(ll n, vector<ll> a){

    ll summ = 0;
    map<ll, ll> stuff;
    for(ll i=0; i<n; i++) {
        summ += a[i];
        stuff[summ] = i;
    }

    ll best = 0;
    summ = 0;
    for(ll i=n-1; i>=0; i--) {
        summ += a[i];
        if(stuff.count(summ) != 0 and stuff[summ] < i) {
            best = (best < summ ? summ : best);
        }
    }

    printf("%lld\n", best);
    return best;    

}

//void validation(ll start_seed, ll end_seed, ll n) {
//
//    clock_t t0 = clock();
//    for(ll s=start_seed; s<=end_seed; s++) {
//        srand(s);
//        vector<ll> a;
//        for(ll i=0; i<n; i++) {
//            a.push_back(rand()%10000);
//        }
//        //for (auto x : a) {
//        //    printf("%lld, ", x);
//        //}
//        //printf("\n");
//        //if(solution2(n, a) != solution(n, a)) {
//        //    printf("failed at seed: %lld\n", s);
//        //}
//        if(solution1(n, a) != solution2(n, a)) {
//            printf("INCORRECTE AT SEED: %lld\n", s);
//        }
//    }
//    clock_t t1 = clock();
//
//    printf("time: %f\n", (float)(t1 - t0)/CLOCKS_PER_SEC);
//
//}

int main() {

    // variables
    ll n;
    cin >> n;

    vector<ll> arr; arr.resize(n);
    for(ll i=0; i<n; i++) {
        scanf("%lld", &arr[i]);
    }
    
    //validation(746, 746, 1000);
    solution2(n, arr);
    
    return 0;
}

