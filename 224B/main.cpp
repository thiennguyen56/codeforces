#include<iostream>
#include<vector>

using namespace std;

void solve() {
	int n, k;
	vector <int> a;
	vector <int> freq;
	freq.resize(100005, 0);
	cin >> n >> k;
	a.resize(n, 0);
	for (int i = 0; i < n; i++) {
		cin>>a[i];
	}
	int numDif = 0;
	for (int i = 0; i < n; i++) {
		freq[a[i]]++;
		if (freq[a[i]] == 1) {
			numDif++;
		}
		if (numDif == k) {
			for (int l = 0; l <= i; l++) {
				freq[a[l]]--;
				if (freq[a[l]] == 0) {
					cout << l + 1 << ' ' << i + 1;
					return;
				}
			}
			break;
		}
	}
	
	cout << -1 << ' '<< -1;
}

int main() {
	solve();
	return 0;
}
