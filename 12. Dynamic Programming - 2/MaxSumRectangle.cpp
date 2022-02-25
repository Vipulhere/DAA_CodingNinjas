#include<bits/stdc++.h>
using namespace std;
int kadane(int *a, int c) {
	int sum = 0, best = 0;
	for (int i = 0; i < c; i++) {
		sum = max(a[i], sum + a[i]);
		best = max(best, sum);
	}
	return best;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int a[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}
		int maxm = INT_MIN;
		for (int i = 0; i < n; i++) {
			int temp[m];
			memset(temp, 0, sizeof(temp));
			for (int j = i; j < n; j++) {
				for (int k = 0; k < m; k++) {
					temp[k] += a[j][k];
				}
				maxm = max(maxm, kadane(temp, m));
			}
		}
		cout << maxm << endl;
	}
}