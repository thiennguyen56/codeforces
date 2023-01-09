#include <iostream>

using namespace std;

int a[300005];
int n, k;

int main() {
  int ans = 0;
  int l = 1;
  int resL = -1;
  int resR = -1;
  int countZero = 0;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) {
      countZero++;
    }
    while (countZero > k) {
      if (a[l] == 0) {
        countZero--;
      }
      l++;
    }
    if (ans < i - l + 1) {
      ans = i - l + 1;
      resL = l;
      resR = i;
    }
  }
  cout << ans << endl;
  for (int i = resL; i <= resR; i++) {
    a[i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << " ";
  }
}
