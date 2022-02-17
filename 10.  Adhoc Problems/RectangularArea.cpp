#include<bits/stdc++.h>
using namespace std;

//Time comp => O(max_x)
//calculate the area on one side of the y axis and then twice it at last to get final ans

int main(){
	int n;
	cin >>n;
	//Index i shows the x point, and value at ith index shows the max height at x point
	int *height = new int[5000000 + 2]();
	//This will store the boundary point of x
	int max_x =0;
	for(int i=0; i<n; i++){
		int x,y;
		cin >>x>>y;
		//if my current height at x point is lesser than y, then i update my height at that point
		if(height[x/2] < y){
			height[x/2] = y;
		}
		if((x/2) > max_x){
			max_x = x/2;
		}
	}
	
	long long area = 0;
	for(int i=max_x; i>0; i--){
		if(height[i] < height[i+1]){
			height[i] = height[i+1];
		}
		area += height[i];
	}
	
	cout << 2*area << endl;
	return 0;
}