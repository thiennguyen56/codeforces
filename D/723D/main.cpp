#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 50;
int n, m, k;
bool visited[MAX_N][MAX_N];
string a[MAX_N];
int lakes = 0;
int transformed = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void init() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      visited[i][j] = false;
    }
  }
}
void DFS(pair<int, int> start) {
  int x = start.first;
  int y = start.second;
  visited[x][y] = true;
  if (lakes > k) {
    a[x][y] = '*';
  }
  for (int i = 0; i < 4; i++) {
    int xx = x + dx[i];
    int yy = y + dy[i];
    if (xx >= 1 && xx < n - 1 && yy >= 1 && yy < m - 1 &&
        visited[xx][yy] == false && a[xx][yy] == '.') {
      DFS(make_pair(xx, yy));
    }
  }
}

void solve() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  init();
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m - 1; j++) {
      if (a[i][j] == '.' && visited[i][j] == false) {
        lakes++;
        DFS(make_pair(i, j));
        if (lakes > k) {
          transformed++;
        }
      }
    }
  }
  cout << transformed << endl;
  for (int i = 0; i < n; i++) {
    cout << a[i] << endl;
  }
}

int main() {
  solve();
  return 0;
}
