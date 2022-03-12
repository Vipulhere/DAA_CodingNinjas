#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mex = 1e5 + 3;
ll eulerphi[mex];
ll ans[mex];

void sieve() {
	for (ll i = 0; i < mex; i++) {
		eulerphi[i] = i;
	}
	for (ll i = 2; i < mex; i++) {
		if (eulerphi[i] == i) {

			for (ll j = i; j < mex; j += i) {
				eulerphi[j] = (eulerphi[j] * (i - 1) / i);
			}
		}
	}


	for (ll i = 1; i < mex; i++) {
		for (ll j = i; j < mex; j += i) {
			ans[j] += (eulerphi[i] * i);
		}
	}

}
int main() {
	sieve();
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		cout << n*(ans[n] + 1) / 2 << endl;
	}
}