#include<iostream>

using namespace std;

void solve() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int start = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] - start <= 15) {
			start = a[i];
		} else {
			cout << start + 15;
			return;
		}
	}
	if (90 - start < 15) {
		cout << 90;
	} else {
		cout << start + 15;
	}
}

int main() {
	solve();
	return 0;
}
