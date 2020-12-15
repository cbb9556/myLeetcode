#include <string>
#include <iostream>
#include "Solution.h"
using namespace std;

int main() {
	string s,p;
	Solution2 test;
	cout<<"s = ";
	cin>>s;
	cout<<"p = ";
	cin>>p;
	cout<<boolalpha<<bool(test.isMatch(s,p))<<endl;
    return 0;
}
