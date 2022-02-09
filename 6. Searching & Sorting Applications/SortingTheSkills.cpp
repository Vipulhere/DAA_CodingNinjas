#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		vector<int> a(n);
		for(int i = 0 ; i < n ; ++i) {
			cin >> a[i];
		}

		string ans = "Yes";

		for(int i = 0 ; i < n-1 ; ++i) {
			if(a[i] > a[i+1]) {
				if(a[i] - a[i+1] == 1) {
					swap(a[i], a[i+1]);
				}
				else {
					ans = "No";
				}
			}
		}

		cout << ans << '\n';
	}
	return 0;
}