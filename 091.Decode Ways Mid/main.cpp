#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;

int main(int argc, char const *argv[]) {
	string s1 = "horse";
	cin>>s1;
	Solution tet;
	cout<<tet.numDecodings(s1)<<endl;
	return 0;
}