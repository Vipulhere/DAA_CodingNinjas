#include<bits/stdc++.h>
using namespace std;
#define ll long long

int stair(int n, int *arr){
    
    int m = pow(10, 9) + 7;
    if(n==0 || n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    if(arr[n]>0){
        return arr[n];
    }
    int output = stair(n-1, arr) + stair(n-2, arr) + stair(n-3,arr);
    arr[n] = output%m;
    
    int ans = output%m;
    return ans;
}

ll stair1(ll n, ll *arr){
    
    int m = pow(10,9)+7;
    
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    
    for(ll i = 3;i<=n;i++){
        arr[i] = (arr[i-1]+arr[i-2]+arr[i-3])%m;
    }
    ll ans = arr[n]%m;
    return ans;
}

int main(){
    
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll *arr = new ll[n+1];
        cout<<stair1(n, arr)<<endl;
    }
    // write your code here
    return 0;
}