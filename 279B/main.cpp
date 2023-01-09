#include<iostream>
#include <vector>
using namespace std;

void solve() {
	int n, t;
	cin >> n >> t;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int total = -1;
	int saveLeft = 0;
	int sum = 0;
	for (int r = 0; r < n; r++) {
		sum += a[r];
		while (sum > t) {
			sum -= a[saveLeft];
			saveLeft++;
		}
		if (total < (r - saveLeft + 1)) {
			total = r - saveLeft + 1;
		}
	}
	cout << total;
}

int main() {
	solve();
	return 0;
}
