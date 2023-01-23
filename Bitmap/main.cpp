#include <iostream>
#include <queue>
#include <string>
#include <utility>

using namespace std;
const int MAX_N = 185;
int dist[MAX_N][MAX_N];
string a[MAX_N];
int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void init() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dist[i][j] = -1;
    }
  }
}

void BFS() {
  queue<pair<int, int>> myqueue;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '1') {
        dist[i][j] = 0;
        myqueue.push(make_pair(i, j));
      }
    }
  }

  while (!myqueue.empty()) {
    pair<int, int> curLocation = myqueue.front();
    myqueue.pop();
    int x = curLocation.first;
    int y = curLocation.second;
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if (xx >= 0 && xx < n && yy >= 0 && yy < m && dist[xx][yy] == -1) {
        dist[xx][yy] = dist[x][y] + 1;
        myqueue.push(make_pair(xx, yy));
      }
    }
  }
}

void solve() {
  int numTest;
  cin >> numTest;
  for (int tc = 1; tc <= numTest; tc++) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    init();
    BFS();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << dist[i][j] << " ";
      }
      cout << endl;
    }
  }
}

int main() {
  solve();
  return 0;
}
