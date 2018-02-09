#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	
	string str = "tact coap";
	int count =0;
	bool flag_odd;
	unordered_map<char, int> string_map;

	int len = str.length();
	for(int i =0;i<len;i++){
		if (str.at(i) == ' ')
			continue;
		string_map[str.at(i)]++;
		count++;
	}
	flag_odd = (count%2 == 1) ? true: false;
	unordered_map<char, int> :: iterator itr;
	for(itr = string_map.begin(); itr != string_map.end(); itr++){
		if(itr->second % 2 == 1){
			if (flag_odd)
				flag_odd = false;				
			else{
				cout<<"not a palindrom";
			}
		}
		
	}
	return 0;
}