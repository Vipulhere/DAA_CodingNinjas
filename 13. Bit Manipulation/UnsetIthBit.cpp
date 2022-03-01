#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll t;
	cin >> t;
	while (t--) {
		ll n, i;
		cin >> n >> i;
		if (n & (1 << i)) {
			ll x = n ^ (1 << i);
			cout << x << endl;
		}
		else {
			cout << n << endl;
		}
	}
}