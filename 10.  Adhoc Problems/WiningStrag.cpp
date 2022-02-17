#include<bits/stdc++.h>
using namespace std;

/*
1. Any player can swap with the player directly at front him
2. One player can swap at most with two other players
If the specific order is formed then our team will win otherwise we will lose
Time comp => O(n)
A perfect sequence can be formed if the numbers are displaced atmost two poisiton from the initial position
if the numbers satisfies this,  then we calculate the number of swaps that will be required to make a perfect sequence
for ex =>  2 1 5 3 4 can be formed in a perfect sequence  but not 2 5 1 3 4 (5 is displaced more than 2 positions)
Now Initial state: 1 2 3 4 5
Three moves required to form this order: 1 2 3 4 5 -> 1 2 3 5 4 -> 1 2 5 3 4 -> 2 1 5 3 4
*/

void solve(int arr[], int n)
{
	// to check the answer
	for (int i = 0; i < n; i++)
	{
		if (abs(arr[i] - i - 1) > 2)
		{
			cout << "NO" << endl;
			return;
		}
	}
	int cnt = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (arr[i] != (i + 1))
		{
			if (((i - 1) >= 0) && arr[i - 1] == (i + 1))
			{
				cnt++;
				swap(arr[i], arr[i - 1]);
			}
			else if (((i - 2) >= 0) && arr[i - 2] == (i + 1))
			{
				cnt += 2;
				arr[i - 2] = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = i + 1;
			}
			else
			{
				printf("NO\n");
				return;
			}
		}
	}
	printf("YES\n%d\n", cnt);
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
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		solve(arr, n);
	}
}