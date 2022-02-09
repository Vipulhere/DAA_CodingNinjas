#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

bool check(const int& k, const int& n) {
	int sharma = 0, singh = 0;

	int x = n, step = 1;
	while(x) {
		// sharma's turn
		sharma += min(k, x);
		x -= min(k, x);

		// singh's turn
		singh -= (x / 10);
		x -= (x / 10);
	}
	return (2*sharma >= n);
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;

		int ans = n;

		int left = 1, right = n;
		while(left <= right) {
			int mid = left + (right - left) / 2;
			if(check(mid, n)) {
				ans = mid;
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}