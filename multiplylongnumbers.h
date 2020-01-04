#include <string>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#ifndef MULTIPLYLONGNUMBERS_H
#define MULTIPLYLONGNUMBERS_H

string BigNumbersMultipication(string one , string two) {

	//If string two > string one just return the reversed call function 
	if(two.size() > one.size()) {
		return BigNumbersMultipication(two,one);
	}

	string answer; //It stores the answer to be returned.

	//n & m stores the corresponding sizes of the strings.
	ll n = one.size() , m = one.size();

	//This array will store the answer which will be
	//converted into a string later on , initialised
	//with 0.
	int* ans = new int[n+m]{};

	//Reversing the strings for easy multipication.
	reverse(one.begin() , one.end());
	reverse(two.begin() , two.end());

	for(int i=0 ; i < one.size() ; i++) {
		for(int j=0 ; j < two.size() ; j++) {

			//As we are multiplying the strings 
			//so must convert string literal to integer.
			int x = (one[i]-'0')*(two[j]-'0');

			ans[i+j] += x;
			//This will give carry to next coming digit.
			ans[i+j+1] += ans[i+j]/10;  
			//Stores value in the current digit.
			ans[i+j] %= 10;
		}
	}
	//storing the inverse as we had reversed the strings above.
	for(int i= n+m-1 ; i >= 0 ; i--) { answer += to_string(ans[i]); }
	delete ans;
	
	//To remove the redundant zeros using substr method.	
	int index = 0;
	for(int i= 0 ; i < answer.size(); i++) {
		if(answer[i] != '0') {break;} 
		index++;
	}
	string main_string = answer.substr(index);

	return main_string;
}
#endif
