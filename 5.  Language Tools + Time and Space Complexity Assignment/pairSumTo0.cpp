// #include<iostream>
// #include<algorithm>
// #include<map>
// using namespace std;

// void PairSum(int *arr, int n)
// {
//     sort(arr, arr+n);
//     int starting_position_of_positive_elements=0;
//     while(arr[starting_position_of_positive_elements]<0)
//     {
//     	starting_position_of_positive_elements++;
// 	}
// 	map<int, int>m;
// 	for(int i=starting_position_of_positive_elements; i<n; i++)
// 	{
// 		m[arr[i]]+=1;
// 	}
// 	for(int i=0; i<starting_position_of_positive_elements; i++)
// 	{
//         int temp=m[-arr[i]];
// 		if(temp>0)
// 		{
// 			while(temp--)
// 			{
// 				cout<<arr[i]<<" "<<-arr[i]<<endl;
// 			}
// 		}
// 	}
// }


#include <bits/stdc++.h>
using namespace std;

int pairSum(int *arr, int n) {
	sort(arr, arr + n);

	unordered_map<int, int> frequency;
	for(int i = 0 ; i < n ; ++i) {
		frequency[arr[i]]++;
	}

	// array without duplicates
	vector<int> v;
	for(int i = 0 ; i < n ; ++i) {
		if(v.empty() || arr[i] != v.back()) {
			v.push_back(arr[i]);
		}
	}

	int count = 0;

	// if the a[i] == 0 first include those pairs
	if(frequency[0] > 0) {
		count += (frequency[0] * (frequency[0] - 1)) / 2;
	}

	int left = 0, right = v.size()-1;
	while(left < right) {
		if(v[left] + v[right] < 0) {
			++left;
		}
		else if(v[left] + v[right] > 0) {
			--right;
		}
		else {
			count += (frequency[v[left]] * frequency[v[right]]);
			--right;
			++left;
		}
	}
 	return count;
}