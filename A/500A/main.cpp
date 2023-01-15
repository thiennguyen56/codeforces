#include<iostream>

using namespace std;
int a[30005];
int n, t;

int main() {
	cin >> n >> t;
	for (int i = 1; i < n; i++) {
		cin >> a[i];
	}
	int p = 1;
	while (p < t) {
		p = p + a[p];
	}
	if (p == t) {
		cout << "YES";
	} else {
		cout << "NO";
	}
	return 0;
}
