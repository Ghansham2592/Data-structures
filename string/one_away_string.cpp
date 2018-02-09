//There are three types ofedit that can be prformed

#include <bits/stdc++.h>
using namespace std;


bool check_one_away(string str, string str_edit){
	int str_length = str.length();
	int str_edit_length = str_edit.length();
	int count =0;
	int count_rem =0;

	if ((str_edit_length < str_length-1) || (str_edit_length > str_length+1)) return false;

	unordered_map<char, int> ump;
	for(int i = 0; i<str_length; i++){
		ump[str.at(i)]++;
	}
	for(int i = 0; i<str_edit_length; i++){
		ump[str_edit.at(i)]++;
		

		if (ump[str_edit.at(i)] == 1){
			count++;
		}
		if (ump[str_edit.at(i)] > 1){
			count_rem++;
		}
		if (count > 1 || (count_rem < str_length && count ==1 )){ 
			return false;}
	}
	return true;	
}

int main(){
	string str = "pale";
	string str_edit = "plk";

	cout<<check_one_away(str, str_edit);
	return 0;
}