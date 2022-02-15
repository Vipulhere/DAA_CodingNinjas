#include<bits/stdc++.h>
using namespace std;

#define n 10

void printer(char cross[n][n]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << cross[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

bool isValidVertical(char cross[n][n], int row, int col, string word){
	int j = row;
	for(int i=0;i<word.length();i++){
		if(j>=n){
			return false;
		}
		if(cross[j][col] == '+' || (cross[j][col] != '-' && cross[j][col] != word[i])){
			return false;
		}
		if(cross[j][col] == '-' || cross[j][col] == word[i]){
			j++;
		}
	}
	return true;
}

bool isValidHorizontal(char cross[n][n], int row, int col, string word){
	int j = col;
	for(int i=0;i<word.size();i++){
		if(j>=n){
			return false;
		}
		if(cross[row][j] == '+' || (cross[row][j] != '-' && cross[row][j] != word[i])){
			return false;
		}
		if(cross[row][j] == '-' || cross[row][j] == word[i]){
			j++;
		}
	}
	return true;
}

void set_vertical(char cross[n][n], int row, int col, vector<bool>& v, string word){
	int r = row;
	for(int i=0;i<word.length();i++){
		if(cross[r+i][col] == '-'){
			cross[r+i][col] = word[i];
			v.push_back(true);
		}
		else{
			v.push_back(false);
		}
	}
}

void reset_vertical(char cross[n][n], int row, int col, vector<bool> v){
	int r = row;
	for(int i=0;i<v.size();i++){
		if(v[i]){
			cross[r+i][col] = '-';
		}
	}
}

void set_horizontal(char cross[n][n], int row, int col, vector<bool>& v, string word){
	int c = col;
	for(int i=0; i<word.length(); i++){
		if(cross[row][c+i] == '-'){
			cross[row][c+i] = word[i];
			v.push_back(true);
		}
		else{
			v.push_back(false);
		}
	}
	
}

void reset_horizontal(char cross[n][n], int row, int col, vector<bool> v){
	int c = col;
	for(int i=0;i<v.size();i++){
		if(v[i]){
			cross[row][c+i] = '-';
		}
	}
}

bool crossword(char cross[n][n],vector<string> words, int index){
	if(index>=words.size()){
		printer(cross);
		return true;
	}
	for(int r = 0; r<n; r++){
		for(int c=0; c<n; c++){
			if(cross[r][c] == '-' || cross[r][c] == words[index][0]){
				if(isValidVertical(cross,r,c,words[index])){
					vector<bool> helper;
					set_vertical(cross, r, c, helper, words[index]);
					if(crossword(cross,words,index+1)){
						return true;
					}
					reset_vertical(cross,r,c,helper);
				}
				if(isValidHorizontal(cross,r,c,words[index])){
					vector<bool> helper;
					set_horizontal(cross,r,c,helper,words[index]);
					if(crossword(cross,words,index+1)){
						return true;
					}
					reset_horizontal(cross,r,c,helper);
				}
			}
		}
	}
	return false;
}

int main(){

	char arr[n][n];
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		for(int j=0;j<n;j++){
			arr[i][j] = s[j];
		}
	}

	string s;
	cin >> s;
	vector<string> words;
	for(int i=0;i<s.length();i++){
		int j = i;
		while(s[j] != ';' && j<s.length()){
			j++;
		}
		words.push_back(s.substr(i,j-i));
		i=j;
		j++;
	}

	bool ans = crossword(arr,words,0);

	return 0;
}