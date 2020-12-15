#include "Solution.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	Solution s1;
	string rom = "MVXCI";
	cout<<"please input:"<<endl;
	cout<<s1.romanToInt(rom)<<endl;
	return 0;
}