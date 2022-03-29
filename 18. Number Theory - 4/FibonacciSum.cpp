#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli mod = 1000000007;

void multiply(lli A[2][2], lli B[2][2]){
    lli firstval = (A[0][0] * B[0][0] + A[0][1] * B[1][0])%mod;
    lli secondval = (A[0][0] * B[0][1] + A[0][1] * B[1][1])%mod;
    lli thirdval = (A[1][0] * B[0][0] + A[1][1] * B[1][0])%mod;
    lli fourthval = (A[1][0] * B[0][1] + A[1][1] * B[1][1])%mod;
    
    A[0][0] = firstval%mod;
    A[0][1] = secondval%mod;
    A[1][0] = thirdval%mod;
    A[1][1] = fourthval%mod;
    
}

void power(lli A[2][2], lli n){
    if(n == 0 || n == 1)
        return ;
    power(A, n/2);
    //multipy A^n/2  A^n/2
    multiply(A, A);
    if(n%2 != 0){
        lli B[2][2] = {{1, 1}, {1, 0}};
        multiply(A, B);
    }
}

lli fib(lli n){
    if(n == 0)
        return 0;
    lli A[2][2] = {{1, 1}, {1, 0}};
    power(A, n-1);
    return A[0][0];
    
}


int fibSum(lli n, lli m){
    lli first = fib(m+2)%mod;
    lli second = fib(n+1)%mod;    
    int sum = int((first%mod - second%mod + mod)%mod);
    return sum; 
}
int main(){
    
    int t;
    cin >> t;
    while(t--){
        lli n, m;
        cin >> n >> m;
        cout << fibSum(n, m) << endl;
    }
    return 0;
}