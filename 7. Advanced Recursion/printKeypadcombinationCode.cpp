#include <iostream>
#include <string>
using namespace std;

void printKeypadHelper(int num, string output, string options[10]){
	if(num == 0){
		cout << output << endl;
		return;
	}
	
	int lastDigit = num%10;
	int i =0;
	while(i < options[lastDigit].length()){
		printKeypadHelper(num/10 , options[lastDigit][i] + output, options);
		i++;
	}
	return;
}

void printKeypad(int num){
	string options[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	printKeypadHelper(num, "", options);
	return;
}
