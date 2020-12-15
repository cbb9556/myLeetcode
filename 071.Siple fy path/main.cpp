#include <iostream>
#include <vector>
#include <string>
#include "Solution.h"
using namespace std;

int main(int argc, char const *argv[]) {
	string s= "/a/b/c/../././///c/";
	//cin>>s;
	cout<<s.substr(2,4)<<endl;
	Solution tet;
	cout<<tet.simplifyPath(s)<<endl;
	return 0;
}