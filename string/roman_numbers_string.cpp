#include <iostream>
#include <string>
using namespace std;
int test(char c){
		switch(c){
			case 'I': return 1; 
				break;
			case 'V':	return 5;
				break;
			case 'X':	return 10;
				break;
			case 'L':	return 50;
				break;
			case 'C':	return 100;
				break;
			case 'D':	return 500;
				break;
			case 'M':	return 1000;
				break;
		}

}

int main() {
        string str ="MCMXCVI";
		int len = str.length();
		int number = 0;
		int j = 1;
		for(int i = 0;i<len;i++){
			int a =test(str[i]);
			int b = i == len-1? 0: test(str[i+1]);
			if (a<b) {
				number = number + b-a;
				i++;
			}
			else number = number + a;	
	}
		cout<<number;
        return 0;
}