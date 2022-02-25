#include<bits/stdc++.h>
using namespace std;

int minNum(int n, int *arr){
    
    int *dp = new int[n+1];
    
    dp[0] = 1;
    
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1]){
            dp[i] = dp[i-1] + 1; 
        }
        else{
            dp[i] = 1;
        }
    }
    
    for(int i=n-2;i>=0;i--){
        if(arr[i]>arr[i+1] && dp[i]<=dp[i+1]){
            dp[i] = dp[i+1] + 1;
        }
    }
    
    int sum = 0;
    for(int i=0;i<n;i++){
        sum = sum + dp[i];
    }
    
    return sum;
}



int main(){
    
    // write your code here
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int *score = new int [n];
        for(int i=0;i<n;i++){
            cin>>score[i];
        }
        
        cout<<minNum(n, score)<<endl;
    }
    
    return 0;
}