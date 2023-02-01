#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> pq, tmp;
  for (int func = 1; func <= n; func++) {
    int action, value;
    cin >> action;
    if (action == 1) {
      cin >> value;
      pq.push(value);
    } else if (action == 2) {
      cin >> value;
      tmp.push(value);
    } else {
      while (pq.empty() == false && tmp.empty() == false &&
             pq.top() == tmp.top()) {
        pq.pop();
        tmp.pop();
      }
      cout << pq.top() << endl;
    }
  }
}
int main() {
  solve();
  return 0;
}
