#include <iostream>
#include <vector>

using namespace std;
const int MAX_N = 22;
int m, n;
bool visited[MAX_N][MAX_N];
string a[MAX_N];
vector<pair<int, int>> entry;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void init() {
  entry.clear();
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      visited[i][j] = false;
      if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && a[i][j] == '.') {
        // cout << i << " " << j << "=" << a[i][j] << endl;
        entry.push_back(make_pair(i, j));
      }
    }
  }
}

void DFS(pair<int, int> start) {
  int x = start.first;
  int y = start.second;
  visited[x][y] = true;
  for (int i = 0; i < 4; i++) {
    int xx = x + dx[i];
    int yy = y + dy[i];
    if (xx >= 0 && xx < m && yy >= 0 && yy < n && visited[xx][yy] == false &&
        a[xx][yy] == '.') {
      DFS(make_pair(xx, yy));
    }
  }
}

void solve() {
  int nt;
  cin >> nt;
  for (int tc = 1; tc <= nt; tc++) {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
      cin >> a[i];
    }
    init();
    if ((int)entry.size() != 2) {
      cout << "invalid" << endl;
    } else {
      DFS(entry[0]);
      if (visited[entry[1].first][entry[1].second] == true) {
        cout << "valid" << endl;
      } else {
        cout << "invalid" << endl;
      }
    }
  }
}

int main() {
  solve();
  return 0;
}
