#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
int main() {
	ll t;
	cin >> t;
	while (t--) {

		string s;
		cin >> s;
		ll l = s.length();
		ll dp[l + 1];
		dp[0] = 1;
		unordered_map<char, ll>mp;
		for (ll i = 1; i <= l; i++) {
			dp[i] = (2 * dp[i - 1]) % mod;
			if (mp.count(s[i - 1])) {
				ll j = mp[s[i - 1]];
				dp[i] -= dp[j - 1];
				dp[i] = (dp[i] + mod) % mod;
			}
			mp[s[i - 1]] = i;

		}
		cout << dp[l] << "\n";
	}
	return 0;
}