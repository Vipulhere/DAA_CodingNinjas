#include<bits/stdc++.h>
using namespace std;
int solve(int n) {
	if (n % 4 == 0) {
		return n;
	}
	if (n % 4 == 1) {
		return 1;
	}
	if (n % 4 == 2) {
		return n + 1;
	}
	return 0;
}
int main() {

	// write your code here
	int t;
	cin >> t;
	while (t--) {

		int n;
		cin >> n;
		cout << solve(n) << endl;

	}
	return 0;
}