#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define MAXN 1000005
using namespace std;
ll phi[MAXN];
ll dp[MAXN];
ll ans[MAXN];
bool isprime[MAXN];
void sieve() {
	//memset(isprime,true,sizeof(isprime));
	isprime[0] = false;
	isprime[1] = false;
	for (ll i = 2; i * i < MAXN; i++) {
		if (isprime[i]) {
			for (ll j = i * i; j < MAXN; j += i) {
				isprime[j] = false;
			}
		}
	}

}
void euler() {
	for (ll i = 1; i < MAXN; i++)
		phi[i] = i;
	for (ll i = 2; i < MAXN; i++) {
		if (phi[i] == i) {
			phi[i] -= 1;
			for (ll j = 2 * i; j < MAXN; j += i)
				phi[j] = (phi[j] * (ll)(i - 1)) / (ll)i;
		}
	}




}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(isprime, true, sizeof(isprime));
	sieve();
	euler();
	ll n, q;
	cin >> n >> q;
	ll a[n];
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll dep[n + 1];
	dep[0] = 0;
	if (isprime[phi[a[0]]]) {
		dep[1] = 1;
	}
	else {
		dep[1] = 0;
	}
	/*	 cout<<isprime[5]<<endl;
		 for(ll i=0;i<n;i++){
		 	cout<<isprime[phi[a[i]]]<<" ";
		 } */
//	 cout<<endl;//
	for (ll i = 1; i <= n; i++) {
		if (isprime[phi[a[i - 1]]]) {
			dep[i] = dep[i - 1] + 1;
		}
		else {
			dep[i] = dep[i - 1];
		}

	}

	while (q--) {
		ll l, r;
		cin >> l >> r;

		cout << dep[r] - dep[l - 1] << endl;
	}
	return 0;
}