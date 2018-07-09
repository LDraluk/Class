#include <iostream>
#include <vector>

using std::vector;
using std::pair;

int recur(vector<vector<int> >& adj, int x,int y, vector<bool>& visited){
    if (x == y) {
        return 1;
    }
    size_t m = adj[x].size();
    visited[x] = true;
    for (int i=0; i<m; i++) {
        int z = adj[x][i];
        if (!visited[z]) {
            if ( recur(adj,z,y,visited)){
                return 1;
            }
        }
    }
    return 0;
}
int reach(vector<vector<int> > &adj, int x, int y) {
    size_t n = adj.size();
    vector<bool> visited(n);
    for (int i=0;i<n; i++) {
        visited[i] = false;
    }
    return recur(adj,x,y,visited);
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
    int x, y;
    std::cin >> x >> y;
    std::cout << reach(adj, x - 1, y - 1);
}


