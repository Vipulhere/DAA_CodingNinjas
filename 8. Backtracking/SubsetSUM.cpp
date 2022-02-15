// #include <bits/stdc++.h>
// using namespace std;
 
// int subsetSum(int a[], int n, int sum)
// {
//     // Initializing the matrix
//     int tab[n + 1][sum + 1];
//   // Initializing the first value of matrix
//     tab[0][0] = 1;
//     for (int i = 1; i <= sum; i++)
//         tab[0][i] = 0;
//     for (int i = 1; i <= n; i++)
//         tab[i][0] = 1;
 
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= sum; j++)
//         {
//           // if the value is greater than the sum
//             if (a[i - 1] > j)
//                 tab[i][j] = tab[i - 1][j];
//             else
//             {
//                 tab[i][j] = tab[i - 1][j] + tab[i - 1][j - a[i - 1]];
//             }
//         }
//     }
//     return tab[n][sum];
// }

// int main(){
//     int t; cin >> t;
//     while(t--){
//         int n,sum; cin >> n >> sum;
//         int a[n];
//         for(int i=0;i<n;i++){
//             cin >> a[i];
//         }
//         cout << (subsetSum(a, n, sum)) << endl;
//     }
// }


#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

int countWays(const vector<int>& a, int k, int index) {
	if(index == a.size()) {
		return k == 0;
	}

	int count = 0;
	if(k - a[index] >= 0) {
		count += countWays(a, k - a[index], index+1);
	}
	count += countWays(a, k, index+1);
	return count;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	string s = "abs";

	int t; cin >> t;
	while(t--)
	{	
		int n, k;
		cin >> n >> k;

		vector<int> a(n);
		for(int i = 0 ; i < n ; ++i) {
			cin >> a[i];
		}

		cout << countWays(a, k, 0) << '\n';
	}
	return 0;
}

