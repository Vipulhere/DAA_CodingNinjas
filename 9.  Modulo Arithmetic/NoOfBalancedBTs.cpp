#include<bits/stdc++.h>
using namespace std;

int balancesBT(int h){
	if(h==0 || h==1)
		return 1;

	int m = pow(10,9) + 7;
	int x = balancesBT(h-1);
	int y = balancesBT(h-2);

	long res1 = (long)x*x;
	long res2 = (long)x*y*2;

	int ans1 = (int)(res1%m);
	int ans2 = (int)(res2%m);

	int ans = (ans1 + ans2)%m;

	return ans;
}


int main(){

	int t;
    cin>>t;
    while(t--){
		int h;
		cin>>h;
		cout<<balancesBT(h)<<endl;
    }
	return 0;
}