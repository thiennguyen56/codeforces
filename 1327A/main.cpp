#include<iostream>

using namespace std;

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, k;
		cin >> s >> k;
		long long sum = 1LL * k * k;
		if ((sum <= s) && (sum - s) % 2 == 0) {
			cout << "YES";
		} else {
			cout << "NO";
			
		}
		cout << endl;
	}
}

int main() {
	solve();
	return 0;
}
