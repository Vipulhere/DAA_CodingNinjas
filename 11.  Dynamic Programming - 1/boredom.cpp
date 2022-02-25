#include<bits/stdc++.h>
using namespace std;
#define ll long long


int boredom(int n, int *arr){
    
    int dp[1001];
    int freq[1001];
    
	//map<int, int> freq;
    
    for(int i=0;i<=1000;i++){
        dp[i] = 0;
        freq[i] = 0;
    }
     
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    
    dp[1] = freq[1];
    for(int i=2;i<=1000;i++){
        
        dp[i] = max( (dp[i-2] + i*freq[i]), dp[i-1] ); 
        
    }
    
    return dp[1000];
    
}



int main(){
    
    // write your code here
    
    int t; 
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int * arr = new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        cout<<boredom(n, arr)<<endl;
    }
    return 0;
}