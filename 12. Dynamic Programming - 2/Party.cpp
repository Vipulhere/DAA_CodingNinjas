#include<bits/stdc++.h>
using namespace std;
int main() {

	// write your code here
	int n;
	cin >> n;
	int fee[n];
	for (int i = 0; i < n; i++) {
		cin >> fee[i];
	}
	int fun[n];
	for (int i = 0; i < n; i++) {
		cin >> fun[i];
	}
	int budget;
	cin >> budget;
	int cost = 0;
	int dp[n + 1][budget + 1];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= budget; j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
			}
			else if (fee[i - 1] <= j) {
				dp[i][j] = max(dp[i - 1][j], fun[i - 1] + dp[i - 1][j - fee[i - 1]]);

			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
			//cout<<dp[i][j]<<" ";
		}//cout<<endl;

	}
	cost = 1000001;
	int fun_value = dp[n][budget];
	for (int i = 1; i <= budget; i++) {
		if (dp[n][i] == fun_value) {
			cost = min(cost, i);
		}
	}
	cout << cost << " " << dp[n][budget];
	return 0;
}