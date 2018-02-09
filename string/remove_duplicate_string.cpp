#include <iostream>
#include <cstring>
using namespace std;
void remove_dup(char *s){
	int count = 1;
	int len = strlen(s);
	for(int i = 1;i<len;i++){
		int j;
		for(j =0; j<count; j++){
			if(s[j]==s[i])
			{ break;}
		}
		if (count ==j){
			s[count] = s[i];	
			++count;
		}
		
		}
	s[count] =0;
}

int main() {
        char s[] ="harshad";
		remove_dup(s);
		cout<<s;
        return 0;
}