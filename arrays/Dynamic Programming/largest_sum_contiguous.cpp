//kadane's algorithm


#include <iostream>
using namespace std;

int main(){

	int max_final=0, max_curr=0;
	int a[]=  {-2, -3, 4, -1, -2, 1, 5, -3};
	int len = sizeof(a)/sizeof(a[0]);
	for(int i =0; i<len;i++){
		max_curr= max_curr + a[i];
		if(max_curr < 0)
			max_curr =0;
		else
			if (max_final < max_curr)
				max_final = max_curr;
	}
	cout<<max_final;
	return 0;
}