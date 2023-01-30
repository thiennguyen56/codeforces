#include <iostream>
#include <vector>

using namespace std;
const int MAX_N = 100005;
int m, n;
vector<int> adj[MAX_N];
int state[MAX_N];
bool isLoop = false;

void init() {
  for (int i = 1; i <= n; i++) {
    adj[i].clear();
    state[i] = 0;
  }
}

void DFS(int u) {
  if (isLoop == true) {
    return;
  }
  state[u] = 1;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (state[v] == 0) {
      DFS(v);
    } else if (state[v] == 1) {
      isLoop = true;
      return;
    }
  }
  state[u] = 2;
}

int main() {
  int testcases;
  cin >> testcases;
  for (int tc = 1; tc <= testcases; tc++) {
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
    }
    isLoop = false;
    for (int i = 1; i <= n; i++) {
      if (state[i] == 0) {
        DFS(i);
      }
    }
    if (isLoop == true) {
      cout << "SIM" << endl;
    } else {
      cout << "NAO" << endl;
    }
  }
}
