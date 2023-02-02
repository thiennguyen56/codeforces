#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 105;
const int inf = 1e9;
int n;
int limit;
int dist[MAX_N];
vector<pair<int, int>> adj[MAX_N];

void init() {
  for (int i = 0; i < MAX_N; i++) {
    adj[i].clear();
    dist[i] = inf;
  }
}

void Dijkstra(int start) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push(make_pair(0, start));
  dist[start] = 0;
  while (!pq.empty()) {
    pair<int, int> tmp = pq.top();
    pq.pop();
    int u = tmp.second;
    if (tmp.first > dist[u])
      continue;
    for (int i = 0; i < (int)adj[u].size(); i++) {
      pair<int, int> V = adj[u][i];
      int w = V.second;
      int v = V.first;
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.push(make_pair(dist[v], v));
      }
    }
  }
}

void solve() {
  cin >> n;
  int start;
  cin >> start;
  cin >> limit;
  int e;
  cin >> e;
  init();
  for (int i = 0; i < e; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[v].push_back(make_pair(u, w));
  }
  Dijkstra(start);
  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (dist[i] <= limit) {
      res++;
    }
  }
  cout << res << endl;
}

int main() {
  solve();
  return 0;
}
