#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*ll num_codes2(ll* n, ll size, ll* arr) {
    
    ll m = pow(10,9) + 7;
    
     if (size == 1) {
         return 1;
     }
     if (size == 0) {
         return 1;
     }
    
    ll output = 0;
    
     if (arr[size] > 0) {
         return arr[size];
     }
    if(n[size-1] != 0){
		output += num_codes2(n, size - 1, arr)%m;
        output %= m;
    }
     if (n[size - 2] * 10 + n[size - 1] <= 26 &&  n[size-2]!=0) {
         output += num_codes2(n, size -2, arr)%m;
         output %= m;
     }
     arr[size] = output;
     return output;
}*/
int num_codes(int *arr, int n){
    
    int mod = pow(10,9) + 7;
    int *output = new int[n+1];
    output[0] = 1;
    output[1] = 1;
    for(int i=2;i<=n;i++){
        output[i] = output[i-1];
        if(arr[i-1] == 0)
        {
            if(arr[i-2] == 1 || arr[i-2] == 2)
            {
                output[i] = output[i-2];
            }
            else output[i] = 0;
        }
        else
        {
            int x = (arr[i-2]*10 + arr[i-1]);
            if(x >= 10 && x <= 26)
            {
                output[i] += output[i-2];
            }
        }
        output[i] = output[i]%mod;
    }
    int ans = output[n];
    delete [] output;
    return ans;
}


int main() {
    
    ll t;
    cin>>t;
    while(t--){
        
        string s;
        cin>>s;
        int *arr = new int[s.size()+1];
        int *num = new int[s.size()];
        for( ll i=0;i<s.size();i++){
            num[i] = s[i] - '0';
        }
        
        cout<<num_codes(num, s.size())<<endl;
        
    }
    return 0;

}