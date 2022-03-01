#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {

	// write your code here
	ll t;
	cin >> t;
	while (t--) {
		ll n, i;
		cin >> n >> i;
		cout << (n | (1 << i)) << endl;
	}
	return 0;
}