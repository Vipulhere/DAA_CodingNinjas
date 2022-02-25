#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct knap {
	ll value, weight;
};
bool compare(knap k1, knap k2) {
	return k1.value < k2.value;
}
ll DP(knap* arr, int n, ll w, int prime[11]) {
	ll*** dp = new ll**[2];
	dp[0] = new ll*[n + 1];
	dp[1] = new ll*[n + 1];
	for (int i = 0; i < n + 1; i++) {
		dp[0][i] = new ll[w + 1]();
		dp[1][i] = new ll[w + 1]();
	}

	for (int r = 1; r < n + 1; r++) {
		for (int c = 1; c < w + 1; c++) {
			dp[0][r][c] = dp[0][r - 1][c];
			if (c - arr[r - 1].weight >= 0)
				dp[0][r][c] = max(dp[0][r - 1][c], dp[0][r - 1][c - arr[r - 1].weight] + arr[r - 1].value);
		}
	}
	int k = 1;
	while (k < 11)
	{
		int v = k % 2;
		for (int r = 1; r < n + 1; r++) {
			for (int c = 1; c < w + 1; c++) {

				dp[v][r][c] = dp[v][r - 1][c];

				if (c - arr[r - 1].weight >= 0)
					dp[v][r][c] = max(dp[v][r - 1][c] , max(dp[v][r - 1][c - arr[r - 1].weight] + arr[r - 1].value ,
					                                        dp[v ^ 1][r - 1][c - arr[r - 1].weight] + prime[k] * arr[r - 1].value));
			}
		}
		k++;
	}
	return dp[0][n][w];
}
int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n, w;
		cin >> n >> w;
		knap* arr = new knap[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i].value;
		}
		for (int i = 0; i < n; i++) {
			cin >> arr[i].weight;
		}
		sort(arr, arr + n, compare);
		int prime[11] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
		cout << DP(arr, n, w, prime) << "\n";
	}

	return 0;
}