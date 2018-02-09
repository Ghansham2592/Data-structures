#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    istringstream iss(s);
    string word;
    while(iss >> word){
    	cout<<word<<'\n';
    }




}