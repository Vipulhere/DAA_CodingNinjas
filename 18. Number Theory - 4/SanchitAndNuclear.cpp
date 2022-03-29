#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll factorial(ll n, ll m) {
	ll ans = 1;
	for (ll i = 2; i <= n; i++) {
		ans = (ans % m * i % m) % m;
	}
	return ans;
}

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, m;
		cin >> n >> m;
		if (n < m) {
			if (m + 1 == n) {
				cout << 1 << endl;
			}
			else {
				cout << factorial(n, m) << endl;
			}
		}
		else {
			ll x = n % m;
			ll ans = factorial(x, m);
			if ((n / m) % 2 == 0) {
				cout << ans << endl;
			}
			else {
				cout << ((m - 1)*ans) % m << endl;
			}
		}
	}

}