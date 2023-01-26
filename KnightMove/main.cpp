#include <iostream>
#include <queue>
#include <string>
#include <utility>
using namespace std;

string xx, yy;
const int n = 8;
const int m = 8;
int dist[n][m];
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

void init() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dist[i][j] = -1;
    }
  }
}

void BFS(pair<int, int> start) {
  queue<pair<int, int>> myqueue;
  myqueue.push(start);
  dist[start.first][start.second] = 0;
  while (!myqueue.empty()) {
    pair<int, int> cur = myqueue.front();
    myqueue.pop();
    int x = cur.first;
    int y = cur.second;
    for (int i = 0; i < 8; i++) {
      int new_x = x + dx[i];
      int new_y = y + dy[i];
      if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m &&
          dist[new_x][new_y] == -1) {
        dist[new_x][new_y] = dist[x][y] + 1;
        myqueue.push(make_pair(new_x, new_y));
      }
    }
  }
}

pair<int, int> convert_to_pair(string input) {
  pair<int, int> output;
  output.second = input[1] - '0';
  output.second -= 1;
  switch (input[0]) {
  case 'a':
    output.first = 0;
    break;
  case 'b':
    output.first = 1;
    break;
  case 'c':
    output.first = 2;
    break;
  case 'd':
    output.first = 3;
    break;
  case 'e':
    output.first = 4;
    break;
  case 'f':
    output.first = 5;
    break;
  case 'g':
    output.first = 6;
    break;
  case 'h':
    output.first = 7;
    break;
  }

  return output;
}
void solve() {
  while (cin >> xx >> yy) {
    init();
    pair<int, int> start = convert_to_pair(xx);
    pair<int, int> end = convert_to_pair(yy);
    BFS(start);
    cout << "To get from " << xx << " to " << yy << " takes "
         << dist[end.first][end.second] << " knight moves." << endl;
  }
}
int main() {
  solve();
  return 0;
}
