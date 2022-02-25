#include<bits/stdc++.h>
using namespace std;
const int mx = 1001;
int main() {
	string s, t;
	cin >> s >> t;
	int l1 = s.length();
	int l2 = t.length();
	int dp[l1 + 1][l2 + 1];
	for (int i = 0; i <= l1; i++) {
		dp[i][0] = 1; // t is empty
	}

	for (int i = 0; i <= l2; i++) {
		dp[0][i] = mx; // s is empty
	}

	for (int i = 1; i <= l1; i++) {
		for (int j = 1; j <= l2; j++) {
			int index = -1;
			for (int k = j - 1; k >= 0; k--) {
				if (t[k] == s[i - 1]) {
					index = k;
					break;
				}
			}
			if (index == -1) {
				dp[i][j] = 1; // that char is not present so it is the answer
			}
			else {
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][index] + 1);
			}
			// cout<<dp[i][j]<<" ";
		}//cout<<endl;
	}
	cout << dp[l1][l2] << endl;
	return 0;
}