#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
ll dp[402][402];
ll open[202];
ll n;
ll brack(ll i, ll o) {
	if (o < 0)return 0;

	if (i == n) {
		if (o == 0) {
			return 1;
		}
		return 0;
	}
	if (dp[i][o] != -1) {
		return dp[i][o];
	}
	if (open[i] > 0) {
		return dp[i][o] = brack(i + 1, o + 1);
	}
	else {
		return dp[i][o] = (brack(i + 1, o + 1) + brack(i + 1, o - 1)) % mod;
	}
}
int main() {
	ll t;
	cin >> t;

	while (t--) {
		memset(dp, -1, sizeof(dp));
		memset(open, 0, sizeof(open));
		ll k;
		cin >> n >> k;
		n *= 2;
		for (ll i = 0; i < k; i++) {
			ll x;
			cin >> x;
			open[x - 1] = 1;
		}
		cout << brack(0, 0) % mod << "\n";

	}
}

/*
other approach
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll dp[402][402];
ll open[202];
ll n;
ll brack(ll o, ll c){
	if(o==n && c==n){
		return 1;
	}
	if(o>n || c>n){
		return 0;
	}
	if(dp[o][c]!=-1){
		return dp[o][c];
	}
	if(o==c || open[o+c]){
		return dp[o][c]=brack(o+1,c);
	}
	else if (o==n){
		return dp[o][c]=brack(o,c+1);
	}
    else{
	return dp[o][c]=(brack(o+1,c)+brack(o,c+1))%mod;
    }
}
int main(){
	ll t;
	cin>>t;
	while(t--){
	memset(dp,-1,sizeof(dp));
    memset(open,0,sizeof(open));
		ll k;
		cin>>n>>k;
		for(ll i=0;i<k;i++){
			ll x;
			cin>>x;
			open[x-1]=1;
		}
		cout<<brack(0,0)%mod<<"\n";
	}
}
*/