#include <bits/stdc++.h>
using namespace std;

double inf = 1e15;

double dis(pair<double, double> p1, pair<double, double> p2)
{
	double a, b;
	a = (p2.first - p1.first) * (p2.first - p1.first);
	b = (p2.second - p1.second) * (p2.second - p1.second);
	return sqrt(a + b);
}

void solve(pair<double, double> arr[], double happy[], int n)
{
	double dp[n];
	dp[0] = happy[0];
	for (int i = 1; i < n; i++)
	{
		dp[i] = -inf;
		for (int j = 0; j < i; j++)
		{
			double x = dis(arr[i], arr[j]); //Find distance between i and j
			dp[i] = max(dp[i], dp[j] - x); //Maximize over all possible
			
		}
        
		dp[i] += happy[i];
	}
	cout << fixed;
	cout << setprecision(6) << dp[n - 1] << endl;
	return;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		pair<double, double> arr[n];
		double a, b;
		double happy[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			arr[i] = make_pair(a, b);
			cin >> happy[i];
		}
		solve(arr, happy, n);
	}
}