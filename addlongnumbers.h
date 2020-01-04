#include <string>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#ifndef ADDLONGNUMBERS_H
#define ADDLONGNUMBERS_H

string AddLongNumbers(string one , string two) {

	if(two.size() > one.size()) {
		return AddLongNumbers(two,one);
	}
	int a = one.size() , b = two.size() , carry = 0;
	string ans;

	reverse(one.begin() , one.end());
	reverse(two.begin() , two.end());

	for(int j=0 ; j<b ; j++) {
		int sum = ((one[j]-'0') + (two[j]-'0') + carry);
		ans.push_back(sum%10 + '0');
		carry = sum/10;
	}

	for(int i=b ;i<a; i++) {
		int sum = ((one[i]-'0') + carry);
		ans.push_back(sum%10 + '0');
		carry = sum/10;
	}

	if(carry > 0) { ans.push_back(carry + '0'); }

	reverse(ans.begin() , ans.end());
	return ans;
}

#endif
