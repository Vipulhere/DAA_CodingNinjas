#include<bits/stdc++.h>

using namespace std;

string temp[]={ "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void keypad_code(int n,string output){
    	if(n==0||n==1){
            cout<<output<<endl;
            return;
        }
    int lastdigit=n%10;
   string input=temp[lastdigit];
   for(int i=0;i<input.size();i++){
     			 keypad_code(n/10,input[i]+output);
   }
}
int main(){
    
    // write your code here
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        keypad_code(n,"");
        //cout<<endl;
    }
    return 0;
}