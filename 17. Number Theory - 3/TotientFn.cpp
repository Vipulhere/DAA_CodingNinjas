#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {

//	ll *arr=new ll[mex]
	ll t;
	cin >> t;
	while (t--) {

		ll n;
		cin >> n;
		ll p = n;
		map<ll, ll>mp;
		for (ll i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				while (n % i == 0) {
					n /= i;
					mp[i]++;
				}
			}
		}
		if (n != 1) {
			mp[n]++;
		}
		ll ans = p;
		for (auto u : mp) {
			ans = (ans / u.first) * (u.first - 1);
			//	cout<<ans<<endl;
		}

		cout << ans << endl;
	}


}