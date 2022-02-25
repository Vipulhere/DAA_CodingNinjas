#include<bits/stdc++.h>
using namespace std;
bool isvalid(int i, int j, int n, int m) {
	if (i >= 0 && i < n && j >= 0 && j < m) {
		return true;
	}
	return false;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int a[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}


		}

		int dp[n + 1][m];
		for (int i = 0; i < m; i++) {
			dp[0][i] = a[0][i];
		}
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (isvalid(i - 1, j - 1, n, m) && isvalid(i - 1, j + 1, n, m)) {
					dp[i][j] = a[i][j] + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i - 1][j + 1]));
				}
				else if (isvalid(i - 1, j - 1, n, m)) {
					dp[i][j] = a[i][j] + dp[i - 1][j - 1];
					dp[i][j] = min(dp[i][j], a[i][j] + dp[i - 1][j]);
				}
				else {
					dp[i][j] = a[i][j] + dp[i - 1][j + 1];
					dp[i][j] = min(dp[i][j], a[i][j] + dp[i - 1][j]);
				}

			}
		}
		int ans = INT_MAX;
		for (int i = 0; i < m; i++) {
			ans = min(ans, dp[n - 1][i]);
		}
		cout << ans << endl;
	}

}