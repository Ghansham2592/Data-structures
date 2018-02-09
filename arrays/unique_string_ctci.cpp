#include <iostream>
#include <unordered_map>
#include <string>
#include <cstring>

using namespace std;

int main(){
	string str = "abcadkj";
	string str1 = "my name is harshad              ";
	int len = str.length();
	unordered_map<char, int> string_map;

	for(int i = 0;i<len;i++){
		if(string_map[str.at(i)] < 1){
			string_map[str.at(i)]++;
		}
		else{
			cout<<"string is not unique";
		}
	}
	str1.replace(str1.begin(), str1.end(), " ", "%20");
	cout<<str1;
	return 0;
}
