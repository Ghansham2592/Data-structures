#include <iostream>
#include <unordered_map>
using namespace std;

int main(){

	unordered_map<char, int> ump_string;
	string str1 = "abcd";
	string str2 = "tyuiyyy";
	bool string_flag=true;

	int len1= str1.length();
	int len2 = str2.length();
	if(len1 == len2){
		for(int i=0; i<len1;i++){
			ump_string[str1.at(i)]++;
			ump_string[str2.at(i)]--;
		}
		for(int i=0; i<len1;i++){
			if(ump_string[str1.at(i)]){
				cout<<"strings are not ana";
				string_flag = false;
				break;
			}

		}
		if(string_flag){
			cout<<"strings are anagram"<<endl;
		}


	}
	else{
		cout<<"strings are not anagram";
	}
	int a=12;
	int *p;
	cout<<endl;
	cout<<&a<<endl<<p<<endl<<*p<<endl<<&p<<endl;
	p = &a;
	cout<<"test"<<endl;
	cout<<&a<<endl<<p<<endl<<*p<<endl<<&p<<endl;
	return 0;
}