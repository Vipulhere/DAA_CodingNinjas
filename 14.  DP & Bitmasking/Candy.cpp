#include<bits/stdc++.h>
using namespace std;

long long candies(int ** like, int n, int person, int mask, long long *dp)
{
    if (person >= n)
    {
        return 1;
    }
    if(dp[mask]!=-1)
    {
        return dp[mask];
    }
    long long ans = 0;
    for (long long i = 0; i < n; i++)
    {
        if (!(mask & (1 << i)) && (like[person][i]==1))
        {
            ans = ans + candies(like, n, person + 1, mask|(1 << i), dp);
        }
    }
    dp[mask]=ans;
    return ans;
}
long long solve(int ** like,int n)
{
	long long *dp = new long long[1 << n];
    for (long long i = 0; i < (1 << n); i++)
    {
        dp[i] = -1;
    }
    long long ans = candies(like, n, 0, 0, dp);
    delete[]dp;
    return ans;
}

int main(){
    
    // write your code here
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin>>n;
        int ** like = new int*[n];
        for(int i=0;i<n;i++){
            like[i]=new int[n];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            	cin>>like[i][j]; //ith person likes or not jth candy
            } 
        }      
        
        long long ans = solve(like, n);      
        
        cout<<ans<<endl;
        
    }
    return 0;
}