// implement an algorithm to determine if string has all unique characters (dont use additional data structure)
#include <bits/stdc++.h>
using namespace std;

bool unique_string(string str){
	unordered_map <char, int> ump;
	for(int i = 0; i<50;i++){
		ump[str.at(i)]++;
		if (ump[str.at(i)] >= 2) return false;
	}

	// unordered_map <char, int>::iterator p;
	// for(p = ump.begin();p!=ump.end();p++){
	// 	cout<<p->first<<"  "<<p->second<<'\n';
	// }
	return true;
}

int main(){
	string str = "my name is is are harshad";
	int str_len = str.length();
	if (str_len > 128)                    //https://www.ascii-code.com/there are 256 ascii code(0-255) but in program we only use 128***
	{
		cout<<"string has duplicate char"<<'\n';
	} 
	else
	{cout<<unique_string(str)<<'\n';
		}
	return 0;
}