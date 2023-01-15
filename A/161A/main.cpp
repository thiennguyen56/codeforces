#include <iostream>
#include <vector>

using namespace std;

struct element {
  int man;
  int vest;
};

void solve() {
  vector<int> a, b;
  vector<element> ans;
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  a.resize(n + 3, 0);
  b.resize(m + 3, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  int p = 1, q = 1;
  while (p <= n && q <= m) {
    if ((b[q] >= a[p] - x) && (b[q] <= a[p] + y)) {
      ans.push_back((element){p, q});
      p++;
      q++;
    } else if (b[q] > a[p] + y) {
      p++;
    } else {
      q++;
    }
  }
  cout << (int)ans.size() << endl;
  for (int i = 0; i < (int)ans.size(); i++) {
    cout << ans[i].man << " " << ans[i].vest << endl;
  }
}

int main() { solve(); }
