#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

void recursion(string& s, int index, char& t, char& r) {
	if(index == s.size()) {
		return;
	}

	if(s[index] == t) {
		s[index] = r;
	}
	recursion(s, index+1, t, r);
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t--)
	{
		string s; cin >> s;
		char t, r;
		cin >> t >> r;

		recursion(s, 0, t, r);

		cout << s << '\n';
	}
	return 0;
}