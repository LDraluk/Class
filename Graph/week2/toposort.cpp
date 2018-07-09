#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using std::vector;
using std::stack;

void dfs(vector<vector<int> > &adj, vector<int> &used, stack<int> &order, int x) {
    used[x] = 1;
    for (int i =0; i< adj[x].size(); i++) {
        int y = adj[x][i];
        if (!used[y]) {
            dfs(adj,used,order,y);
        }
    }
    order.push(x);
}

stack<int> toposort(vector<vector<int> > adj) {
    vector<int> used(adj.size(), 0);
    stack<int> order;
    for (int i=0; i<adj.size(); i++) {
        if (!used[i]) {
            dfs(adj,used,order,i);
        }
    }
    return order;
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
    stack<int> order = toposort(adj);
    while (!order.empty()) {
        std::cout << order.top()+1 << " ";
        order.pop();
    }
    
    /*   for (size_t i = 0; i < order.size(); i++) {
     std::cout << order[i] + 1 << " ";
     }
     */
}

