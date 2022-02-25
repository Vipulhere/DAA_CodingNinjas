#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int calc_pil(int *as, int *cp, int n, int i) {
	if (n == 0)return 0;

	if (dp[n][i] != -1)return dp[n][i];

	if (i == 0) {
		return dp[n][i] = as[0] + calc_pil(as + 1, cp + 1, n - 1, 1);
	}
	else if (i == n) {
		return dp[n][i] = cp[0] + calc_pil(as + 1, cp + 1, n - 1, i - 1);
	}

	return dp[n][i] = min(as[0] + calc_pil(as + 1, cp + 1, n - 1, i + 1), cp[0] + calc_pil(as + 1, cp + 1, n - 1, i - 1));
}


int main() {
	int t;
	cin >> t;
	while (t--) {

		int n;
		cin >> n;
		int as[n];
		int cp[n];
		for (int i = 0; i < n; i++) {
			cin >> cp[i] >> as[i];
		}
		memset(dp, -1, sizeof(dp));
		cout << calc_pil(as, cp, n, 0) << "\n";
	}
}