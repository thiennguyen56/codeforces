#include <iostream>
#include <queue>
using namespace std;

int main() {
  int n;
  cin >> n;
  priority_queue<int> pq;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    pq.push(v);
    if (pq.size() < 3) {
      cout << -1 << endl;
    } else {
      int t1 = pq.top();
      pq.pop();
      int t2 = pq.top();
      pq.pop();
      int t3 = pq.top();
      pq.pop();
      long long res = 1LL * t1 * t2 * t3;
      cout << res << endl;
      pq.push(t2);
      pq.push(t1);
      pq.push(t3);
    }
  }
}
