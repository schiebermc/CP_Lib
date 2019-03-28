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

int main(){
	
	int n, k; scanf("%d %d", &n, &k);
	std::vector<std::pair<int, int>> songs;
	for(int i=0; i<n; i++){
		int len, beauty; scanf("%d %d", &len, &beauty);
		songs.push_back({beauty, len});
	}
	std::sort(songs.begin(), songs.end());
	
	ll totallen = 0, maximal = 0;
	std::multiset<int> optimallens;
	for(int i=n-1; i>=0; i--){
		ll thismaximal = songs[i].first * (totallen + songs[i].second);
		if(thismaximal > maximal) maximal = thismaximal;
		optimallens.insert(songs[i].second); totallen += songs[i].second;
		while(optimallens.size() > k-1){
			totallen -= *(optimallens.begin()); 
			optimallens.erase(optimallens.begin());
		}
	} printf("%lld\n", maximal);
	
	return 0;
}

