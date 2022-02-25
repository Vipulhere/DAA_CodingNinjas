#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[10001][11][2];

ll transaction (ll *a, ll n, ll k, ll cur_status) {
	if (k <= 0) {
		return 0;
	}
	if (n == 0) {
		return 0;
	}
	if (dp[n][k][cur_status] != -1) {
		return dp[n][k][cur_status];
	}


	if (cur_status) {
		return dp[n][k][cur_status] = max(transaction(a + 1, n - 1, k, 1), transaction(a + 1, n - 1, k - 1, 0) + a[0]);
	}
	else {
		if (k > 0) {
			return dp[n][k][cur_status] = max(transaction(a + 1, n - 1, k, 0), transaction(a + 1, n - 1, k, 1) - a[0]);
		}
	}
}
int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, m;
		cin >> n >> m;
		ll a[m];
		for (ll i = 0; i < m; i++) {
			cin >> a[i];
		}

		memset(dp, -1, sizeof(dp));
		cout << transaction(a, m, n, 0) << "\n";
	}
}