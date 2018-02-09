#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void lcs(string s1, string s2, int m ,int n){
int l[m+1][n+1];
int i, j;
for(i= 0; i<=m;i++)
	for(j =0; j<=n; j++){
		if(i== 0 || j==0)
			l[i][j] =0;
		else
			if(s1.at(i-1)==s2.at(j-1)){
				l[i][j] = 1+l[i-1][j-1];
			}
			else{
				l[i][j]= max(l[i-1][j], l[i][j-1]);
			}
	}

	cout<<"Length of Longest Common Subsequence: "<<l[m][n]<<endl;


	// i = m; 
	// j =n;
	// string res= "";
	// while(i>0 && j>0){
	// 	if(s1.at(i-1) ==s2.at(j-1))
	// 		res = res + s1[i-1];
	// 	else
	// 		if(l[i][j] ==l[i-1][j])
	// 			i--;
	// 		else
	// 			j--;
	// }
	// reverse(res.begin(), res.end());
	// cout<<res;
}


int main(){
	string s1 = "AGGTABfg";
	string s2 = "GXTXAYBfg";
	int m = s1.length();
	int n = s2.length();
	lcs(s1, s2, m,n);
	return 0;
}