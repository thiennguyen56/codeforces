#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int m, n;

const int MAX_N = 505;
const int inf = 1e9;

vector<pair<int, int>> V[MAX_N];
int dist[MAX_N];

void init() {
  for (int i = 0; i < MAX_N; i++) {
    V[i].clear();
    dist[i] = inf;
  }
}

void Dijkstra(int s) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push(make_pair(0, s));
  dist[s] = 0;

  while (!pq.empty()) {
    pair<int, int> tmp = pq.top();
    pq.pop();
    int u = tmp.second;
    if (tmp.first > dist[u])
      continue;

    for (int i = 0; i < (int)V[u].size(); i++) {
      pair<int, int> K = V[u][i];

      int v = K.first;
      int w = K.second;

      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.push(make_pair(dist[v], v));
      }
    }
  }
}

int main() {
  cin >> n;
  init();
  for (int i = 0; i < n; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    V[a].push_back(make_pair(b, w));
    V[b].push_back(make_pair(a, w));
  }
  int start;
  cin >> start;
  Dijkstra(start);
  int query;
  cin >> query;
  for (int i = 0; i < query; i++) {
    int v;
    cin >> v;
    if (dist[v] == inf) {
      cout << "NO PATH" << endl;
    } else {
      cout << dist[v] << endl;
    }
  }
  return 0;
}
