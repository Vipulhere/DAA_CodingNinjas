#include <iostream>
using namespace std;

//Time comp => O(N^2)
//We fill the last row and last column by asking the minimum amout of strength required
// Note:  if strength required is 0 or -ve , then take it to be 1
// Now, fill the rest of dp by subtracting grid[i][j] because on that cell, some energy(-ve or +ve) must be provided

int getMinimumStrength(int** grid, int n, int m) {
	// Write your code here
    int ** dp = new int*[n];
	for (int i = 0; i < n; i++) {
		dp[i] = new int[m];
	}
    //base case
    dp[n-1][m-1] = 1;
    for(int i = n-2; i>=0; i--){
        dp[i][m-1] = dp[i+1][m-1] - grid[i][m-1];
        if(dp[i][m-1] <=0){
            dp[i][m-1] = 1;
        }
    }
    for(int j = m-2; j>=0; j--){
        dp[n-1][j] = dp[n-1][j+1] - grid[n-1][j];
        if(dp[n-1][j] <=0){
            dp[n-1][j] = 1;
        }
    }
    
    for (int i = n - 2; i >=0; i--) {
		for (int j = m - 2; j >=0 ; j--) {
			// dp[i][j] = min( dp[i+1][j] - grid[i+1][j] , dp[i][j+1] - grid[i][j+1] ) ;
            dp[i][j] = min( dp[i+1][j] , dp[i][j+1] )  - grid[i][j];
            if(dp[i][j] <=0){
           		dp[i][j] = 1;
        	}
		}
	}
	
    return dp[0][0];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int **grid = new int *[n];

        for (int i = 0; i < n; ++i) {
            grid[i] = new int[m];
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }

        cout << getMinimumStrength(grid, n, m) << "\n";

        for (int i = 0; i < n; ++i) {
            delete[] grid[i];
        }

        delete[] grid;
    }
}