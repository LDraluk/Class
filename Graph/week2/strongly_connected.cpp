#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using std::vector;
using std::stack;
void dfs(vector<vector<int> > &adj, vector<int> &used, int x) {
    used[x] = 1;
    for (int i =0; i< adj[x].size(); i++) {
        int y = adj[x][i];
        if (!used[y]) {
            dfs(adj,used,y);
        }
    }
}
void fill(vector<vector<int> > &adj, vector<int> &used, stack<int> &order, int x) {
    used[x] = 1;
    for (int i =0; i< adj[x].size(); i++) {
        int y = adj[x][i];
        if (!used[y]) {
            fill(adj,used,order,y);
        }
    }
    order.push(x);
}
vector<vector<int> >  transpose(vector<vector<int> >& adj) {
    vector<vector<int> > reverse(adj.size(), vector<int>());
    for (int v =0; v<adj.size(); v++) {
        for (int i =0; i< adj[v].size();i++) {
            reverse[adj[v][i]].push_back(v);
        }
    }
    return reverse;
}
int number_of_strongly_connected_components(vector<vector<int> > adj) {
    int result = 0;
    vector<int> used(adj.size(), 0);
    stack<int> order;
    for (int i=0; i<adj.size(); i++) {
        if (!used[i]) {
            fill(adj,used,order,i);
        }
    }
    vector<vector<int> > reverse = transpose(adj);
    for (int i=0; i < used.size();i++) {
        used[i] = 0;
    }
    while (!order.empty()) {
        int v = order.top();
        order.pop();
        if (!used[v]) {
            result +=1;
            dfs(reverse,used,v);
        }
    }
    
    
    return result;
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
    std::cout << number_of_strongly_connected_components(adj);
}

