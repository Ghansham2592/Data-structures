#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

string lcp(string str, string lcps){
	if (lcps == "") lcps = str;
	string test = "";
	int len = min(str.length(), lcps.length());
	int i;
	for(i =0; i<len;i++){
		if (str[i] != lcps[i]) break;
		test = test + str[i];
	}
return i==0 ? "" :test;

}

int main (){
	string a[] = {"abc","abd","abrfg"};
	string lcps = "";
	int length = sizeof(a)/sizeof(a[0]);
	for(int i= 0; i< length;i++){
		lcps=lcp(a[i],lcps);	
	}
	cout<<lcps;
	return 0;

}