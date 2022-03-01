#include<bits/stdc++.h>
using namespace std;
int main() {

	// write your code here
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		int xorr = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			xorr ^= a[i];
		}
		cout << xorr << endl;

	}
	return 0;
}