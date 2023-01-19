#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  int a[105];
  cin >> n;
  int sum = 0;
  int coin_need;
  int max = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a, a + n);
  int current_sum = 0;
  for (int i = n - 1; i >= 0; i--) {
    current_sum += a[i];
    ++coin_need;
    if (current_sum > sum / 2) {
      break;
    }
  }
  cout << coin_need;
  return 0;
}
