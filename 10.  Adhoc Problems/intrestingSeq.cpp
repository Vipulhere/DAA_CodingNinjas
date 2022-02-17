#include<bits/stdc++.h>
using namespace std;

/*
"interesting" sequence of numbers, which are sequences that have equal elements.  2 options:
1) Choose two elements of sequence . DECREASE the first element by 1 and INCREASE the second element by 1. This operation costs 'k' coins.
2) Choose one element of array and INCREASE it by 1. This operation costs 'l' coins.
What’s the minimum number of coins needs to turn his sequence into a “interesting" sequence .
Time comp => 
Foe ex => arr = 2 3 8 9 11    now all the elements can be made equal to number ranging from 2(min) to 11(max)
So we calculate cost for each each number in range   min <= num <= max    and store the minimum cost
Now, in helper function  (let say num = 7)
1. We calculate the increasing required as  7-2 +  7-3 = 8
2. We calculate the decreasing required as  8-7 +  9-7  11-7 = 7
3. if(increasing >= decreasing)      Total cost = decreasing*k + (increasing - decreasing)*l
*/
int main()
{
	int n, l, k;
	cin >> n >> l >> k;
	int arr[n];
	int min1 = INT_MAX, max1 = INT_MIN;
	long long int ans = 1e15;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		min1 = min(min1, arr[i]);
		max1 = max(max1, arr[i]);
	}
	for (int j = min1; j <= max1; j++)
	{
		int inc = 0, dec = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] < j)
				inc += j - arr[i];
			else
				dec += arr[i] - j;
		}
		if (dec > inc)
			continue;
		ans = min(ans, 1ll * dec * l + (inc - dec) * 1ll * k);
	}
	cout << ans << endl;
	return 0;
}