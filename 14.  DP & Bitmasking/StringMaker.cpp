#include<bits/stdc++.h>
using namespace std;

#define m 1000000007
typedef long long int ll;

int helper(string a, string b, string c, ll ***dp)
{
    if(c.length()==0)
    {
        return 1;
    }
    if(a.length()<=0&&b.length()<=0)
    {
        return 0;
    }
    if(dp[a.length()][b.length()][c.length()]>-1)
    {
        return dp[a.length()][b.length()][c.length()]%m;
    }
    ll ans=0;
    for(ll i=0; i<a.length(); i++)
    {
        if(a[i]==c[0])
        {
            ans+=helper(a.substr(i+1), b, c.substr(1), dp)%m;
        }
    }
    for(ll i=0; i<b.length(); i++)
    {
        if(b[i]==c[0])
        {
            ans+=helper(a, b.substr(i+1), c.substr(1), dp)%m;
        }
    }
    dp[a.length()][b.length()][c.length()]=ans%m;
    return ans%m;
}
int solve(string a, string b, string c)
{
    ll ***dp=new ll **[51];
    for(ll i=0; i<51; i++)
    {
        dp[i]=new ll *[51];
        for(ll j=0; j<51; j++)
        {
            dp[i][j]=new ll [51];
            for(ll k=0; k<51; k++)
            {
                dp[i][j][k]=-1;
            }
        }
    }
    //created dp
    
    
    
    ll ans= helper(a, b, c, dp)%m;
    
    
    //deleting dp
    for(ll i=0; i<51; i++)
    {
        for(ll j=0; j<51; j++)
        {
            delete[]dp[i][j];
        }
    }
    return ans;
}

int main(){
    
    int t;
	cin>>t;
    while(t--){
        string a,b,c;
        cin>>a;
        cin>>b;
        cin>>c;
        
        int ans = solve(a,b,c);
        
        cout<<ans<<endl;
    }
    
    
    return 0;
}