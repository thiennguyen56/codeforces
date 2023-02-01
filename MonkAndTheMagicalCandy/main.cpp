#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

int main() {
  int number_test_cases;
  cin >> number_test_cases;
  for (int tc = 1; tc <= number_test_cases; tc++) {
    int n, k;
    cin >> n >> k;
    priority_queue<long long> pq;
    for (int i = 0; i < n; i++) {
      long long v;
      cin >> v;
      pq.push(v);
    }
    long long res = 0;
    for (int i = 0; i < k; i++) {
      long long top = pq.top();
      res += top;
      pq.pop();
      pq.push(floor(top / 2));
    }
    cout << res << endl;
  }
}
