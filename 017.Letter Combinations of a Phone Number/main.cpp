#include "Solution.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	Solution s1;
	string rom = "23";
	cout<<"please input:"<<endl;
	auto s2 = s1.letterCombinations(rom);
	auto b_itor = s2.begin(), e_itor = s2.end();
	cout<<"[";
	for (auto b_itor = s2.begin(); b_itor != s2.end(); ++b_itor)
	{
		/* code */
		cout<<*b_itor<<",";
	}
	cout<<"]"<<endl;
	return 0;
}