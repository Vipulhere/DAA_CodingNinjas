#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		string s1;
		cin >> s1;
		string s2;
		cin >> s2;
		int l1 = s1.length();
		int l2 = s2.length();
		int dp[l1 + 1][l2 + 1];
		for (int i = 0; i <= l2; i++) {
			dp[0][i] = 0;
		}
		for (int j = 0; j <= l1; j++) {
			dp[j][0] = 0;
		}

		for (int i = 1; i <= l1; i++) {

			for (int j = 1; j <= l2; j++) {

				if (s1[i - 1] == s2[j - 1]) {
					dp[i][j] = 1 + dp[i - 1][j - 1];
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}

		cout << l1 + l2 - dp[l1][l2] << "\n";

	}

	// write your code here
	return 0;
}