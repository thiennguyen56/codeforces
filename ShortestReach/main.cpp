#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int MAX_N = 1005;
int n, m;
vector<int> adj[MAX_N];
int dist[MAX_N];

void init() {
  for (int i = 1; i <= n; i++) {
    adj[i].clear();
    dist[i] = -1;
  }
}

void BFS(int start) {
  queue<int> myqueue;
  myqueue.push(start);
  dist[start] = 0;
  while (!myqueue.empty()) {
    int u = myqueue.front();
    myqueue.pop();
    for (int i = 0; i < (int)adj[u].size(); i++) {
      int v = adj[u][i];
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        myqueue.push(v);
      }
    }
  }
}

int main() {
  int num_test;
  cin >> num_test;
  for (int tc = 1; tc <= num_test; tc++) {
    cin >> n >> m;
    init();
    for (int i = 1; i <= m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    int start;
    cin >> start;
    BFS(start);
    for (int i = 1; i <= n; i++) {
      if (i != start) {
        if (dist[i] == -1) {
          cout << -1 << " ";
        } else {
          cout << 6 * dist[i] << " ";
        }
      }
    }
    cout << endl;
  }
  return 0;
}
