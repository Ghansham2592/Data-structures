//check Permutation: Given two string, write a method to decide if one is permutation of another

#include <bits/stdc++.h>
using namespace std;

bool check_perm(string s){
	string str;
	cout<<"please enter string"<<'\n';
	cin>>str;
	if (str.length() != s.length()) return false;
	unordered_map <char, int> ump;

	for(int i = 0; i<s.length();i++){
		ump[s.at(i)]++;
	}
	for(int i = 0; i<str.length();i++){
		ump[str.at(i)]--;
		if (ump[str.at(i)] < 0)
			return false;
	}
	return true;

}

int main(){
	string s = "abc";
	cout<<check_perm(s);
	return 0;
}
