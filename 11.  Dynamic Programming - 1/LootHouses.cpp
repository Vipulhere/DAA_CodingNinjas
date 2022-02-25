#include <iostream>
using namespace std;

//time comp => O(n)
//Consider building the result array in a bottom-up fashion
// (computing the result for smaller to larger numbers of houses).
// We can observe that if we’re at the ith house, we only require
// the results for the (i-1)th and the (i-2)th houses. Hence, 
//instead of maintaining a whole array, we simply keep track of the
// last two results obtained.
int maxMoneyLooted(int *arr, int n){
    int dp[n+1];
    dp[0] = 0;
    dp[1] = arr[0];
    for(int i=2; i<=n; i++){
        dp[i] = max(dp[i-2]+arr[i-1], dp[i-1]);
    }
    return dp[n];
}

int main(){
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << maxMoneyLooted(arr, n);

	delete[] arr;
}