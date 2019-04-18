
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


// use this in main for directed a rooted tree from undirected input
        unordered_map<ll, vector<ll>> undirected_edges;
        for(ll i=0; i<N-1; i++) { 
            cin >> u >> v;
            add_edge(undirected_edges, u, v);
            add_edge(undirected_edges, v, u);
        } 

        unordered_map<ll, pair<ll, vector<ll>>> tree;
        direct_edges(undirected_edges, tree, 1);

