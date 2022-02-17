#include<bits/stdc++.h>
using namespace std;

/*
A bulb can be ‘ON’ or ‘OFF’. Mr. Navdeep got ‘n’ number of bulbs and their status, 
whether they are ‘ON’ or ‘OFF’. Their status is represented in a string of size ‘n’ 
consisting of 0’s and 1’s, where ‘0’ represents the bulb is in ‘OFF’ condition and ‘1’ 
represent the bulb is ‘ON’. Mr. Navdeep has been given the task to light up all the bulbs.
He can perform two operations.
First, chose any segment of bulbs and reverse them means chose any substring and reverse it.
 E.g. “0 110 001” -> “0 011 001”. Substring (1, 3) is reversed here. This operation will cost him Rs. ‘X’.
Second, chose any segment of bulbs and reverse their present condition. i.e. if the bulb is ‘ON’
, make it ‘OFF’ and if it is ‘OFF’, make it ‘ON’. E.g. “0 011 001” -> “0 100 001”. Substring (1, 3)
 is complemented. This operation will cost him Rs. ‘Y’.
You need to help Mr. Navdeep that how much minimum amount it will require to make all the bulbs lightened.
 (or make all the characters as ‘1’ in the representation string)
Time comp => O(n)
Find the number of groups of bulbs that are off (i.e. substrings of only 0)  
Now, we have to group all the zeros together : two choices => either we make n-1 moves to reverse the substrings 
 or we can make n-1 flips so that all 0s come together.  Then at last we make a final flip to convert all 0s to 1.
*/

long long solve(int n, long long x, long long y, string s){
    int counter =0;
    for(int i=0; i <n; i++){
        if(s[i] == '0'){
            int c=i;
            while(s[c] == '0'){
                c++;
            }
            i = c-1;;
            counter++;
        }
    }
    if(counter == 0){
        return 0;
    }
    long long ans = (counter-1)*min(x, y) + y;
    return ans;
}

int main()
{
    int n;
    cin >>n;
    long long x,y;
    cin >> x >> y;
    string s;
    cin >>s;
    
    cout << solve(n, x, y, s) <<endl;
	return 0;
}