#include<bits/stdc++.h>
using namespace std;
#define ll long long

int productN(ll n){
	if(n==1)
		return 1;
	if(n==0)
		return 0;
	int m = pow(10,9) + 7;
	int res = productN(n-1);
	int ans = (res*n)%m;

	return ans;

}


int main(){
	ll t;
	cin>>t;
	while(t--){
		ll num;
		cin>>num;
		cout<<productN(num)<<endl;
	}

	return 0;
}