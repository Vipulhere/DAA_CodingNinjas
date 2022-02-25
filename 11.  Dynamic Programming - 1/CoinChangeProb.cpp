#include<bits/stdc++.h>
using namespace std;

int coinChange(int n, int *d, int numD, int **dpOutput){
    
    int m = pow(10,9) + 7;
	if(n==0)
		return 1;
	if(n<0)
		return 0;
	if(numD==0)
		return 0;

	if(dpOutput[n][numD] > -1){
		return dpOutput[n][numD];
	}

	int first = coinChange(n-d[0], d, numD, dpOutput);
	int second = coinChange(n, d+1, numD-1, dpOutput);

	dpOutput[n][numD] = (first + second)%m;

    int output = (first+second)%m;
    
	return output;
}

int main(){
	
	//allocate 2d array here,size =  [n + 1] * [numD + 1]
	//put all -1
	
	int t;
    cin>>t;
    while(t--){
        int numD, n;
        cin>>numD;
        int *d = new int[numD];
        for(int i=0;i<numD;i++)
            cin>>d[i];
        cin>>n;
        int ** dpOutput = new int*[n+1];
        for(int i=0;i<n+1;i++){
       		dpOutput[i] = new int[numD+1];
        }
        for(int i=0;i<n+1;i++){
            for(int j = 0;j<numD+1;j++){
                dpOutput[i][j] = -1;
            }
        }
        cout<<coinChange(n, d, numD, dpOutput)<<endl;
    }
	return 0;
}