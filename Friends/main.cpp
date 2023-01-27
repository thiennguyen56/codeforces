#include <iostream>
#include <vector>

using namespace std;
const int MAX_N = 30005;

vector<int> adj[MAX_N];
bool visited[MAX_N];
int cnt = 0;

void DFS(int u) {
  cnt++;
  visited[u] = true;
  for (int i = 0; i < (int)adj[u].size(); i++) {
    int v = adj[u][i];
    if (visited[v] == false) {
      DFS(v);
    }
  }
}

void solve() {
  int nt;
  cin >> nt;
  for (int tc = 1; tc <= nt; tc++) {
    int n, m;
    cin >> n >> m;
    int res = -1;
    for (int i = 1; i <= n; i++) {
      adj[i].clear();
      visited[i] = false;
    }
    for (int i = 1; i <= m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
      if (visited[i] == false) {
        cnt = 0;
        DFS(i);
        if (res < cnt) {
          res = cnt;
        }
      }
    }
    cout << res << endl;
  }
}

int main() {
  solve();
  return 0;
}
