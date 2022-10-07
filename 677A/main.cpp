#include<iostream>

using namespace std;

int a[1001];
void solve() {
	int n, h;
	cin >>n >>h;
	for (int i = 0; i < n; i++){
		cin >>a[i];
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > h) {
			result += 2;
		} else {
			result += 1;
		}
	}
	cout << result;
	return;
}

int main() {
	solve();
	return 0;
}
