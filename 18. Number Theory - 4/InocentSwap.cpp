#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int m = 1e9 + 7;
const int xe = 1e9 + 5;
ll arr[1000001];

void factori() {
	arr[0] = 1;
	for (int i = 1; i < 1000001; i++) {
		arr[i] = (arr[i - 1] % m * i % m) % m;
	}
}

inline ll factorial(ll n) {
	return arr[n];
}
ll binexpo(ll a, ll b) {
	ll ans = 1;
	while (b > 0) {
		if (b & 1)
			ans = (ans * a) % m;

		a = (a * a) % m;
		b >>= 1;
	}
	return ans;
}
int main() {
	factori();
	ll t;
	cin >> t;
	while (t--) {

		ll n, k;
		cin >> n >> k;
		ll x1 = factorial(n);

		ll x2 = factorial(n - k);
		ll x3 = factorial(k);

		ll y1 = binexpo(x2, xe);

		ll y2 = binexpo(x3, xe);

		ll y3 = binexpo(2, k);
		ll ans = (x1 % m * y1 % m * y2 % m * y3 % m) % m;
		cout << ans << endl;
	}

}