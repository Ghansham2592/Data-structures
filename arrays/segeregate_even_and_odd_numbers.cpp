#include <iostream>
using namespace std;


int evenodd(int a[], int len){
	int start_index =0, last_index = len-1, temp;
	bool s_flag = true, l_flag =false;
	for(int i = 0; i< len; i++){
		if (start_index > last_index)
			break;
		if(a[start_index] % 2 == 0 && s_flag ){
			s_flag =false;
		}
		if (s_flag)
			start_index++;
		if(a[last_index] % 2 == 1 && l_flag){
			l_flag = false;
		}
		if (l_flag)
			last_index--;

		if( !s_flag && !l_flag){
			cout<<"test"<<a[start_index]<<" h" <<a[last_index]<<endl;
			temp = a[start_index];
			a[start_index] = a[last_index];
			a[last_index] = temp;
			s_flag = l_flag = true;
		}

	}
	for(int i = 0; i< len; i++){
		cout<<a[i]<<", ";
	}
	cout<<endl;
	return 0;
}

int main() { 
	int a[] = {23,81,86,73,44,32,17,19,20};
	int len = sizeof(a)/sizeof(a[0]);
	evenodd(a, len);
	return 0;	
}