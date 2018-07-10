#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
   vector<int> distance(adj.size(),-1);
   queue<int> q;
   distance[s] = 0;
   q.push(s);
   while (!q.empty()) {
      auto v = q.front();
      if (v==t) {
         return distance[v];
      }
      q.pop();
      for (int i=0; i<adj[v].size(); i++) {
         auto u = adj[v][i];
         if (distance[u] == -1) {
            q.push(u);
            distance[u] = distance[v]+1;
            
         }
      }
   }
   return -1;
}
int bipartite(vector<vector<int> > &adj) {
   vector<int> color(adj.size(),-1);
   queue<int> q;
    color[0] = 1;
   q.push(0);
   while (!q.empty()) {
      auto v = q.front();
      q.pop();
      for (int i=0; i<adj[v].size(); i++) {
         auto u = adj[v][i];
         if (color[u] == -1) {
            q.push(u);
            color[u] = 1 - color[v];
         }
         if (color[u] == color[v]) {
            return 0;
         }
      }
   }
  return 1;
}
int main() {
   int n, m;
   std::cin >> n >> m;
   vector<vector<int> > adj(n, vector<int>());
   for (int i = 0; i < m; i++) {
      int x, y;
      std::cin >> x >> y;
      adj[x - 1].push_back(y - 1);
      adj[y - 1].push_back(x - 1);
   }
/*   int s, t;
   std::cin >> s >> t;
   s--;
   t--;
   std::cout << distance(adj, s, t);
 */
   std::cout << bipartite(adj);
}
