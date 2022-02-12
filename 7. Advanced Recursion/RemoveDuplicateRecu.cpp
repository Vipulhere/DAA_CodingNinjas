#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

void recursion(const string& s, int index, string& ans) {
	if(index == s.size()) {
		return;
	}

	if(index == 0 || (index > 0 && s[index] != s[index-1])) {
		ans += s[index];
	}
	recursion(s, index+1, ans);
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t--)
	{
		string s; cin >> s;
		string ans;

		recursion(s, 0, ans);

		cout << ans << '\n';
	}
	return 0;
}