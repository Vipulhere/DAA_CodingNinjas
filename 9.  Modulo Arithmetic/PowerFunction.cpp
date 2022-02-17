#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll powerfunc(ll x, ll y){

	int m = pow(10,9) + 7;

	ll res = 1;
	for(int i=0;i<y;i++)
		res = (res * x) % m;

	ll ans = res%m;
	return ans;

}



int main(){

	ll t;
	cin>>t;
	while(t--){
		ll x,y;
		cin>>x>>y;
		cout<<powerfunc(x,y)<<endl;
	}
	return 0;
}

//Another Way

#include<bits/stdc++.h>
#define ll long long
#include <math.h>
#include <stdio.h>
using namespace std;
int main(){
    ll t;
	cin>>t;
    while(t--){
        long long x,y;
        long long int res;
        long long int ans;
        cin>>x>>y;
        int m = pow(10,9) + 7;
        res = 1;
		for(int i=0;i<y;i++)
		res = (res * x) % m;
       
        ans = res%m;
        cout<<ans<<endl;
    }
    return 0;
}
