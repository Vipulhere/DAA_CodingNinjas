// #include<iostream>
// #include<map>
// #include<utility>
// #include<vector>
// using namespace std;

// vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
// 	//Your Code goes here
//     vector<pair<int, int> >pairs_vector;
// 	//in this vector first element of each pair is the start and second element is the max_length.
// 	map<int, bool>m;
// 	for (int i = 0; i < n; i++)
// 	{
// 		m[arr[i]] = true;
// 	}
// 	int max_length = 0;
// 	int start = 0;
// 	for (int i = 0; i < n; i++)
// 	{
// 		int current_length = 1;
// 		int current_start = 0;
// 		if (m[arr[i]] = true)
// 		{
// 			m[arr[i]] = false;
// 			//forward propagation from arr[i]
// 			int element_at_position = arr[i];
// 			while (m[element_at_position + 1] == true)
// 			{
// 				current_length += 1;
// 				m[element_at_position + 1] = false;
// 				element_at_position++;
// 			}
// 			//backward propagation from arr[i]
// 			element_at_position = arr[i];
// 			current_start = element_at_position;
// 			while (m[element_at_position - 1] == true)
// 			{
// 				m[element_at_position - 1] = false;
// 				current_start--;
// 				current_length++;
// 				element_at_position--;
// 			}
// 		}
// 		if (current_length >= max_length)
// 		{
// 			max_length = current_length;
// 			start = current_start;
// 			pair<int, int>p;
// 			p.first = start;
// 			p.second = max_length;
// 			pairs_vector.push_back(p);
// 			//in this vector first element of each pair is the START and second element is the MAX_LENGTH.
// 		}
// 	}
// 	if (max_length == 1 && start == arr[n - 1])
// 	{
// 		vector<int>temp;
// 		temp.push_back(arr[0]);
// 		return temp;
// 	}
// 	for (int i = 0; i < n; i++)
// 	{
// 		int starting_element = arr[i];
// 		for (int j = 0; j < pairs_vector.size(); j++)
// 		{
// 			if (starting_element == pairs_vector[j].first && max_length == pairs_vector[j].second)
// 			{
// 				vector<int>temp;
// 				for (int k = starting_element; k < starting_element + max_length; k++)
// 				{
// 					temp.push_back(k);
// 				}
// 				return temp;
// 			}
// 		}
// 	}
// }


#include <bits/stdc++.h>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    unordered_map<int, int> hashMap;
    for(int i = 0 ; i < n ; ++i) {
        hashMap[arr[i]] = i;
    }
    
    sort(arr, arr + n);
    
    int start = 0, end = 0;
    int maxLen = 0;
    
    int i = 0;
    while(i < n) {
        int j = i + 1;
        while(j < n && arr[j] - arr[j-1] == 1) {
            ++j;
        }
        int currLen = j-i;
        if(currLen > maxLen) {
            maxLen = currLen;
            start = arr[i];
            end = arr[j-1];
        }
        else if(currLen == maxLen && hashMap[start] > hashMap[arr[i]]) {
            start = arr[i];
            end = arr[j-1];
        }
        i = j;
    }
    
    vector<int> ans = {start, end};
    return ans;
}