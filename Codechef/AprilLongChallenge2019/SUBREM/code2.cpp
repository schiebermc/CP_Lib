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
#include <stack>

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long int ll;

void get_subtree_weights(unordered_map<ll ,ll> &subtree_weights, 
                         unordered_map<ll, pair<ll, vector<ll>>>& tree, 
                         vector<ll>& weights, ll node) {
    ll weight = weights[node-1];
    if(!tree[node].second.empty()){
        for(auto &x : tree[node].second){
            if(subtree_weights.find(x) == subtree_weights.end())
                get_subtree_weights(subtree_weights, tree, weights, x);
            weight += subtree_weights[x];
        }
    }
    subtree_weights[node] = weight;
}        

tuple<ll, vector<ll>, ll> get_heaviest_subtree_at_root( unordered_map<ll, pair<ll, vector<ll>>>& tree, vector<ll>& weights, ll node, ll root, ll X) {
         
    ll cuts = 0;
    vector<ll> clippings;
    ll this_subtree = weights[node-1];;

    for(auto child : tree[node].second) {
        auto stuff = get_heaviest_subtree_at_root(tree, weights, child, root, X);
        ll val = get<0>(stuff);
        ll these_cuts = get<2>(stuff);
        ll this_cost = val - these_cuts*X; 

        // include this subtree if it's weight minus it's cuts is nonzero        
        if(this_cost >= -X) {

            cuts += these_cuts;
            this_subtree += val; 
            for(auto x : get<1>(stuff))
                clippings.push_back(x);
        } 
        // otherwise cut the shit out of it
        else {
            cuts++;
            clippings.push_back(child);
        }
    }

    ll cost = this_subtree - cuts*X; 
//    printf("node: %lld, cost: %lld, cuts: %lld\n", node, cost, cuts);
    if(cost < -X) {
        // thats zero contribution by this subtree, but one cut
        return {0, {node}, 1};
    } else { 
        // the weight of the subtree. do not include cuts!
        return  {this_subtree, clippings, cuts};
    }
}        

void add_edge(unordered_map<ll, vector<ll>> &edges, ll u, ll v) {
   if(edges.find(u) == edges.end())
       edges[u] = {};
   edges[u].push_back(v);
}

void direct_edges(unordered_map<ll, vector<ll>>& undirected_edges,
                  unordered_map<ll, pair<ll, vector<ll>>>& directed_edges, ll root){
    if(directed_edges.find(root) == directed_edges.end())
        directed_edges[root] = {0, {}};
    for(auto x : undirected_edges[root]) {
        if(x == directed_edges[root].first)
            continue;
        directed_edges[root].second.push_back(x);
        directed_edges[x] = {root, {}};
        direct_edges(undirected_edges, directed_edges, x);
    }
}
            
void get_subtree(ll node, unordered_map<ll, pair<ll, vector<ll>>>& tree, set<ll> &subtree) {
    stack<ll> frontier;
    for(auto child : tree[node].second)
        frontier.push(child);   
    while(not frontier.empty()) {
        ll x = frontier.top();
        frontier.pop();
        subtree.emplace(x);
        for(auto child : tree[x].second)
            frontier.push(child);
    }
}

unordered_map<ll, pair<ll, vector<ll>>> random_rooted_tree(ll N) {
    // 1 based indexing
    // root is assumed to be at 1
    unordered_map<ll, pair<ll, vector<ll>>> tree;
    tree[1] = {-1, {}};
    for(ll i=2; i<=N; i++) {

        ll parent = rand()%N+1;
        // this isn't exactly efficient, but it gaurantees the tree is connected
        while(tree.find(parent) == tree.end() or tree[parent].second.size() == 2 or parent == i) {
            parent = rand()%N+1;
        }
        tree[parent].second.push_back(i);
        // not exactly random, since higher indices will tend to be leaves
        tree[i] = {parent, {}};
    }
    return tree;
}

vector<ll> random_vector(ll N, ll amax, ll amin) {
    if(amax < amin)
        throw;
    ll size = amax - amin;
    vector<ll> vec; vec.resize(N);
    for(ll i=0; i<N; i++) 
        vec[i] = rand()%size+amin;
    return vec;
}

ll brute_force(unordered_map<ll, pair<ll, vector<ll>>>& tree, vector<ll>& A, ll X, ll N) {

    unordered_map<ll, ll> subtree_weights;
    get_subtree_weights(subtree_weights, tree, A, 1);        
                
    vector<ll> best_order;
    ll best = subtree_weights[1];
    vector<ll> myints; myints.resize(N);
    for(ll i=0; i<N; i++) {myints[i] = i+1;}
    
    // literally try every permutation of deletions. ope
    do {

        ll cuts = 0;
        set<ll> nodes;
        auto weights = subtree_weights;
        for(ll i=0; i<N; i++) {nodes.emplace(i+1);}

        vector<ll> current_order = {};
        for(auto node : myints) {

            // delete subtree rooted by this nod    
            if(nodes.find(node) == nodes.end())
                continue;
            set<ll> subtree = {node};
            get_subtree(node, tree, subtree);
            
            // destroy subtree
            for(auto child : subtree)
                nodes.erase(child);
           
            // releif the parent of this burden
            ll parent = node; 
            ll val = weights[parent];
            weights[parent] -= val;    
            while(parent != 1) {
                parent = tree[parent].first;
                weights[parent] -= val;    
            }
            
            current_order.push_back(node);
            cuts++;
//            best = max(best, weights[1] - cuts*X);
            if(best < weights[1] - cuts*X) {
                best = weights[1] - cuts*X;
                best_order = current_order;

            }
        }    
    
    } while ( std::next_permutation(myints.begin() ,myints.end()) ); 

//    printf("best order: ");
//    for(auto x : best_order)
//        printf("%lld ", x);
//    printf("\n");

    return best;
} 

ll solution2(unordered_map<ll, pair<ll, vector<ll>>>& tree, vector<ll>& A, ll X, ll N) {

    unordered_map<ll, ll> subtree_weights;
    get_subtree_weights(subtree_weights, tree, A, 1);        
             
    auto stuff = get_heaviest_subtree_at_root(tree, A, 1, 1, X);       
    auto clippings = get<1>(stuff);
    
    vector<ll> weight_of_clippings;
    for(auto x : clippings)
        weight_of_clippings.push_back(subtree_weights[x]);

//    printf("heaviest: %lld\n", get<0>(stuff));
//    printf("clippings: ");
//    for(auto x : clippings)
//        printf("%lld ", x);
//    printf("\n");

    ll cuts = 0;
    ll summ = subtree_weights[1];
    ll best = subtree_weights[1];
    sort(weight_of_clippings.begin(), weight_of_clippings.end());
    for(auto x : weight_of_clippings) { 
        summ -= x;
        cuts++;
        best = max(best, summ - cuts*X);    
    }
    return best;    
}

ll solution3(unordered_map<ll, pair<ll, vector<ll>>>& tree, vector<ll>& A, ll X, ll N) {

    unordered_map<ll, ll> subtree_weights;
    get_subtree_weights(subtree_weights, tree, A, 1);        
    auto stuff = get_heaviest_subtree_at_root(tree, A, 1, 1, X);       
    return get<0>(stuff) - get<2>(stuff)*X; 
}

void validate(ll start_seed, ll end_seed, ll N, ll amax, ll amin, ll xmax) {

    for(ll s = start_seed; s<= end_seed; s++) {
        srand(s);
        auto tree = random_rooted_tree(N);
        auto weights = random_vector(N, amax, amin);
        ll X = rand()%xmax+1;
        
//        for(auto kv : tree) {
//            printf("node : %lld", kv.first);
//            printf(" [%lld] -  ", kv.second.first);
//            for(auto x : kv.second.second)
//                printf("%lld ", x);
//            printf("\n");
//        }
//      
//        for(ll i=0; i<N; i++) 
//            printf("(%lld, %lld)\n", i+1, weights[i]);
//        
//        printf("X: %lld\n", X); 

        ll val1 = solution3(tree, weights, X,  N);
        ll val2 = solution2(tree, weights, X,  N);
        

        if(val1 != val2)
            printf("failed at seed %lld: %lld vs %lld\n", s, val1, val2);
        else
            printf("succes at seed %lld: %lld vs %lld\n", s, val1, val2);
    }

}

int main() {

    IOS;
    ll t, N, X, u, v;
    cin >> t;

    validate(0, 50, 8, 10, -10, 5);

    for(ll test=0; test<t; test++) {

        cin >> N >> X;
        vector<ll> A; A.resize(N);
        for(ll i=0; i<N; i++) { cin >> A[i]; }
        
        unordered_map<ll, vector<ll>> undirected_edges;
        for(ll i=0; i<N-1; i++) { 
            cin >> u >> v;
            add_edge(undirected_edges, u, v);
            add_edge(undirected_edges, v, u);
        } 

        unordered_map<ll, pair<ll, vector<ll>>> tree;
        direct_edges(undirected_edges, tree, 1);
        
        printf("%lld\n", solution2(tree, A, X, N));

    }

    return 0;
}

