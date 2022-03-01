#include<bits/stdc++.h>
using namespace std;
int main() {

    // write your code here
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;

        int m;
        m = (1 << (i)) - 1;
        cout << (n & m) << endl;

    }
    return 0;
}