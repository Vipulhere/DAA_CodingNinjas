#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {

	// write your code here
	ll t;
	cin >> t;
	while (t--) {
		ll a;
		cin >> a;
		string b;
		cin >> b;
		ll m;
		cin >> m;
		ll l = b.length();
		ll result = 1;
		for (ll i = l - 1; i >= 0; i--) {

			if (b[i] == '0') {

			}
			else if (b[i] == '1') {
				result = (result % m * a % m) % m;
			}
			else if (b[i] == '2') {
				result = ((result % m * a % m) * a % m) % m;
			}
			a = ((a * a) % m * a) % m;

		}
		cout << result << endl;

	}
	return 0;
}