#include <iostream>
using namespace std;



void lcs(int a[], int n){

	int lcs_size[n];

	for(int i =0; i<n;i++){
		lcs_size[i] =1;
	}

	for(int i =0; i<n;i++)
		for(int j= 0;j<i;j++){
			if(a[i]> a[j] && (lcs_size[i] < lcs_size[j] +1))
				lcs_size[i] = lcs_size[j] + 1;
		}
	int max = lcs_size[0];
	for(int i =1; i<n;i++){
		if (max < lcs_size[i])
			max = lcs_size[i];
	}

	cout<<max<<endl;

}

int main(){
	int a[] = { 10, 22, 30 ,9, 33, 21, 50, 41, 60 };
	
	int n = sizeof(a)/sizeof(a[0]);
	lcs(a, n);

	return 0;
}

