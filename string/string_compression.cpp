#include <bits/stdc++.h>
using namespace std;


void string_compress(string str){
	bool string_compress_flag = true;
	unordered_map<char,int> ump;
	for(int i= 0; i< str.length();i++){
		ump[str.at(i)]++;
		if (string_compress_flag && ump[str.at(i)] > 1){
			string_compress_flag = false;
		}
	}
	for(int i= 0; i< str.length();){
		if (string_compress_flag)
			cout<<str.at(i);
		else
			cout<<str.at(i)<<ump[str.at(i)];
			if (ump[str.at(i)] ==1)
				i = i+1;
			else
				i = i+ ump[str.at(i)];
	}


}


int main(){
	string str = "abcd";
	string_compress(str);
	return 0;
}