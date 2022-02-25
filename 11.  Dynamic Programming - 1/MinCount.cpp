#include<bits/stdc++.h>
using namespace std;

int minCount(int n){
    
    int *dp = new int[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    
    for(int i=1;i*i<=n;i++){
        
        for(int j=0; i*i+j <= n;j++){
            dp[i*i + j] = min(dp[i*i + j], 1+dp[j]);
        }
    }
   
    
    return dp[n];
}


int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<minCount(n)<<endl;
    }
    return 0;
}