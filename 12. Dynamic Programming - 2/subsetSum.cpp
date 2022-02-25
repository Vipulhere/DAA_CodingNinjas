#include<bits/stdc++.h>
using namespace std;
int dp[501][501];
bool sbsum(int *a, int k, int n) {
	if (k == 0) {
		return true;
	}
	if (n <= 0) {
		return false;
	}

	if (dp[n][k] != -1) {
		return dp[n][k];
	}
	if (k >= a[n - 1]) {
		return dp[n][k] = sbsum(a, k - a[n - 1], n - 1) || sbsum(a, k, n - 1);
	}
	else {
		return dp[n][k] = sbsum(a, k, n - 1);
	}

}

int main() {

	// write your code here
	int t;
	cin >> t;
	while (t--) {
		memset(dp, -1, sizeof(dp));
		int n;
		cin >> n;
		int sb[n];
		for (int i = 0; i < n; i++) {
			cin >> sb[i];
		}

		int k;
		cin >> k;

		if (sbsum(sb, k, n)) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}


	}
	return 0;
}