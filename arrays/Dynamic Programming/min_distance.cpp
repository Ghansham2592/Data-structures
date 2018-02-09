#include <iostream>
#include <algorithm>
using namespace std;


void  min_path(int a[][3], int m , int n ){
	int cash[m][n];
	cash[0][0] = a[0][0];

	for(int i = 1; i<m;i++)
		cash[i][0] = cash[i-1][0] + a[i][0];

	for(int j = 1; j<n;j++)
		cash[0][j] = cash[0][j-1] + a[0][j];

	for(int i =1; i<m;i++)
		for(int j=1; j<n; j++){
			cash[i][j] = min(cash[i-1][j], min(cash[i][j-1], cash[i-1][j-1])) + a[i][j];
		}

		cout<<cash[2][2]<<endl;
}

int main(){
	int a[3][3] = {{1,2,3}, {4,8,2}, {1,5,3}};
	min_path(a,3,3);
	return 0; 
}