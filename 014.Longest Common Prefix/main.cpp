#include "Solution.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	Solution s1;
	std::vector<string> rom = {"MVXCI","MVDVC","MVKDSA"};
	cout<<"please input:"<<endl;
	cout<<s1.longestCommonPrefix(rom)<<endl;
	return 0;
}