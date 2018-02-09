#include <bits/stdc++.h>
using namespace std;





int main(){
	int n = 2;
	int arr[2][2] = {{1,2},{3,4}};
	int arr_temp[2][2] ={};
	for(int i = 0;i<2;i++){
		for(int j = 0;j<2;j++){
			arr_temp[j][n-1] = arr[i][j];
		}
		n = n-1;
	} 

	for(int i = 0;i<2;i++){
		for(int j = 0;j<2;j++){
			cout<<arr_temp[i][j];
		}
		cout<<'\n';
	} 

	return 0;
}