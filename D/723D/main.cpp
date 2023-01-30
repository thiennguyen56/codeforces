#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX_N = 53;
int n, m, k, cnt = 0;
string a[MAX_N], tmp[MAX_N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct element {
  int square;
  int x, y;
};

vector<element> save;

bool cmp(const element &a, const element &b) { return (a.square < b.square); }

void DFS(pair<int, int> start) {
  int x = start.first;
  int y = start.second;
  cnt++;
  a[x][y] = '*';
  for (int i = 0; i < 4; i++) {
    int xx = x + dx[i];
    int yy = y + dy[i];
    if (xx >= 0 && xx < n && yy >= 0 && yy < m && a[xx][yy] == '.') {
      DFS(make_pair(xx, yy));
    }
  }
}

void solve() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    tmp[i] = a[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && a[i][j] == '.') {
        DFS(make_pair(i, j));
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '.') {
        cnt = 0;
        DFS(make_pair(i, j));
        save.push_back((element){cnt, i, j});
      }
    }
  }
  for (int i = 0; i < n; i++) {
    a[i] = tmp[i];
  }
  sort(save.begin(), save.end(), cmp);
  int res = 0;
  for (int i = 0; i < save.size() - k; i++) {
    res += save[i].square;
    DFS(make_pair(save[i].x, save[i].y));
  }
  cout << res << endl;
  for (int i = 0; i < n; i++) {
    cout << a[i] << endl;
  }
}

int main() {
  solve();
  return 0;
}
