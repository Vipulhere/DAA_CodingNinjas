#include <bits/stdc++.h>
using namespace std;

string uniqueChar(string str) {
    string ans;
    
    unordered_set<char> frequency;
	for(int i = 0 ; i < str.size() ; ++i) {
		frequency.insert(str[i]);
	}

	for(int i = 0 ; i < str.size() ; ++i) {
		if(frequency.find(str[i]) != frequency.end()) {
			ans += str[i];
			frequency.erase(str[i]);
		}
	}
    return ans;
}