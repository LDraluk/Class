#include <iostream>
#include <vector>

using std::vector;
using std::pair;
void recur(vector<vector<int> >& adj, int x, vector<bool>& visited){
    size_t m = adj[x].size();
    visited[x] = true;
    for (int i=0; i<m; i++) {
        int z = adj[x][i];
        if (!visited[z]) {
            recur(adj,z,visited);
        }
    }
}
int number_of_components(vector<vector<int> > &adj) {
    int res = 0;
    size_t n = adj.size();
    vector<bool> visited(n);
    for (int i=0;i<n; i++) {
        visited[i] = false;
    }
    for (int i=0; i<n; i++) {
        if (!visited[i]) {
            res +=1;
            recur(adj, i,visited);
        }
    }
    return res;
}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (size_t i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    std::cout << number_of_components(adj);
}

