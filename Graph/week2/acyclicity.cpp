#include <iostream>
#include <vector>

using std::vector;
using std::pair;
int is_cycle(vector<vector<int> > &adj,int v,vector<pair<bool,bool>>& visited) {
    visited[v] = std::make_pair(true,true);
    for (int i=0; i<adj[v].size(); i++) {
        int y = adj[v][i];
        std::pair<bool,bool> vis = visited[y];
        if (!vis.first && is_cycle(adj,y,visited)) {
            return 1;
        }
        if (vis.second) {
            return 1;
        }
    }
    visited[v] = std::make_pair(true,false);
    return 0;
}
int acyclic(vector<vector<int> > &adj) {
    size_t n = adj.size();
    vector<pair<bool,bool>> visited(n);
    for (int i=0; i<n; i++) {
        visited[i] = std::make_pair(false,false);
    }
    for (int i=0; i<n; i++) {
        if ( is_cycle(adj,i,visited)) {
            return 1;
        }
    }
    
    return 0;
}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (size_t i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
    }
    std::cout << acyclic(adj);
}
