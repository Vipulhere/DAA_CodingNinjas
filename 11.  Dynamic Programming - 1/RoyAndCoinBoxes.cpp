#include <bits/stdc++.h>
using namespace std;
int main()
{
	//for fast input and output
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, q, l, r;
		cin >> n >> m;
		int start[n + 1], end[n + 1], coins[n + 1], ans[n + 1];
		for (int i = 0; i <= n; i++)
		{
			start[i] = 0;
			end[i] = 0;
			coins[i] = 0;
			ans[i] = 0;
		}
		for (int i = 0; i < m; i++)
		{
			cin >> l >> r;
			start[l]++; //noting the times the starting box was kth box
			end[r]++; //noting the times the ending box was kth box
		}
		int temp = 0;
		for (int i = 1; i <= n; i++)
		{
			temp += start[i];
			coins[i] = temp;
			temp -= end[i];
		}
		//now calculate how many boxes have exact i coins
		for (int i = 1; i <= n; i++)
		{
			ans[coins[i]]++;
		}
		/*now calculate how many boxes have atleast i coins which is same as
		number of boxes having atleast i+1 coins + number of boxes having exact i
		coins
		Note: box with atleast max coins is same as box with exact k coins
		In other words we can take max as n and start iterating from n-1*/
		for (int i = n - 1; i > 0; i--)
		{
			ans[i] = ans[i] + ans[i + 1];
		}
		cin >> q;
		while (q--)
		{
			cin >> temp;
			cout << ans[temp] << endl;
		}
	}
	return 0;
}