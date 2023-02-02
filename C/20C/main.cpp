#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 100005;
const long long inf = 1e15;
int n, m;
int path[MAX_N];
vector<pair<int, int>> adj[MAX_N];
long long dist[MAX_N];

void init() {
  for (int i = 1; i <= n; i++) {
    adj[i].clear();
    dist[i] = inf;
    path[i] = -1;
  }
}

void Dijkstra(int start) {
  priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                 greater<pair<long long, int>>>
      pq;
  pq.push(make_pair(0LL, start));
  dist[start] = 0;
  while (!pq.empty()) {
    pair<long long, int> tmp = pq.top();
    pq.pop();
    int u = tmp.second;
    long long distance = tmp.first;
    if (distance > dist[u])
      continue;
    for (int i = 0; i < (int)adj[u].size(); i++) {
      pair<int, int> V = adj[u][i];
      int v = V.first;
      int w = V.second;
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.push(make_pair(dist[v], v));
        path[v] = u;
      }
    }
  }
}

void solve() {
  cin >> n >> m;
  init();
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }
  Dijkstra(n);
  /*for (int i = 1; i <= n; i++) {*/
  /*cout << dist[i] << endl;*/
  /*}*/
  if (dist[1] == inf) {
    cout << -1 << endl;
  } else {
    int v = 1;
    cout << v << " ";
    while (path[v] != -1) {
      cout << path[v] << " ";
      v = path[v];
    }
  }
}

int main() {
  solve();
  return 0;
}
