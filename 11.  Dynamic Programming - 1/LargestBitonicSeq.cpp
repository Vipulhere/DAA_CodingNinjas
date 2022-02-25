#include<bits/stdc++.h>
using namespace std;

int lbs(int n, int *a){
    
	int *forward = new int[n];
    int *backward = new int[n];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j])
                forward[i] = max(forward[i], 1+forward[j]);
        }
    }
    for(int i = n-1;i>=0;i--){
        for(int j = n-1;j>i;j--){
            if(a[i]>a[j])
                backward[i] = max(backward[i], 1+backward[j]);
        }
    }
    
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans, forward[i] + backward[i] - 1);
    }
    
    return ans+2;
}



int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int *arr = new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        cout<<lbs(n, arr)<<endl;
    }
    return 0;
}