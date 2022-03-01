#include<bits/stdc++.h>
using namespace std;
int main() {

	// write your code here
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		for (int i = 0; i < 32; i++) {
			if (n & (1 << i)) {
				n = (n ^ (1 << i));
				cout << n << "\n";
				break;
			}
		}
	}
	return 0;
}