#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mex = 1e5 + 1;
ll arr[mex];
void sieve() {

	for (ll i = 0; i < mex; i++) {
		arr[i] = i;
	}


	for (ll i = 2; i < mex; i++) {
		if (arr[i] == i) {
			arr[i] -= 1;
			for (ll j = 2 * i; j < mex; j += i) {
				arr[j] = arr[j] * (i - 1) / i;
			}
		}
	}



}



int main() {

	ll t;
	cin >> t;
	sieve();
	ll result[mex];
	memset(result, 0, sizeof(result));
	for (ll i = 1; i < mex; i++) {
		for (ll j = 2; i * j < mex; j++) {
			result[i * j] += (i * arr[j]);
		}
	}
	ll dp[mex];
	dp[0] = result[0];
	for (ll i = 1; i < mex; i++) {
		dp[i] = result[i] + dp[i - 1];
	}
	while (t--) {
		ll n;
		cin >> n;
		ll sum = 0;
		cout << dp[n] << endl;

	}
}