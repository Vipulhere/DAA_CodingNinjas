#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
ll dp[101][101][2];
ll fun_cnt_bit(ll n, ll k, ll first) {
	if (dp[n][k][first] != -1) {
		return dp[n][k][first];
	}
	if (n == 1) {
		if (k == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	if (k < 0) {
		return mod;
	}

	if (first) {
		return dp[n][k][first] = (fun_cnt_bit(n - 1, k - 1, 1) + fun_cnt_bit(n - 1, k, 0)) % mod;
	}
	else {
		return dp[n][k][first] = (fun_cnt_bit(n - 1, k, 0) + fun_cnt_bit(n - 1, k, 1)) % mod;
	}
}
int main() {
	ll t;
	cin >> t;
	memset(dp, -1, sizeof(dp));
	while (t--) {
		ll n, k;
		cin >> n >> k;
		cout << (fun_cnt_bit(n, k, 0) + fun_cnt_bit(n, k, 1)) % mod << "\n";

	}
}