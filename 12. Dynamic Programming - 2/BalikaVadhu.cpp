#include<bits/stdc++.h>
using namespace std;
string s1, s2;
int dp[101][101][101];
int bbadhu(int i, int j, int k, int n, int m) {
	if (i == n || j == m) {
		if (k > 0) {
			return INT_MIN;

		}
		else {
			return 0;
		}

	}


	if (dp[i][j][k] != -1) {
		return dp[i][j][k];
	}

	if (s1[i] == s2[j]) {
		if (k > 0) {
			return dp[i][j][k] = max(s1[i] + bbadhu(i + 1, j + 1, k - 1, n, m), max(bbadhu(i + 1, j, k, n, m), bbadhu(i, j + 1, k, n, m)));
		}
		else {
			return 0;
		}
	}
	else {
		return dp[i][j][k] = max(bbadhu(i + 1, j, k, n, m), bbadhu(i, j + 1, k, n, m));
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {

		int k;
		cin >> s1 >> s2 >> k;
		memset(dp, -1, sizeof(dp));
		cout << max(0, bbadhu(0, 0, k, s1.length(), s2.length())) << "\n";


	}
}