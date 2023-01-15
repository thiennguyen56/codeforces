#include<iostream>
#include<vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector <int> a;
	a.resize(n, 0);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	int count_zero = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			count_zero++;
		}
	}
	
	if ((count_zero == 1 && n > 1) || (count_zero == 0 && n == 1)) {
		cout << "YES";
	} else {
		cout << "NO";
	}
}

int main() {
	solve();
	return 0;
}
