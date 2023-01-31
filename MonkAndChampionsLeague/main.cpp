#include <iostream>
#include <queue>

using namespace std;

int main() {
  int m, n;
  cin >> m >> n;
  priority_queue<int> pq;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    pq.push(x);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int t = pq.top();
    pq.pop();
    ans += t;
    pq.push(t - 1);
  }
  cout << ans << endl;
}
