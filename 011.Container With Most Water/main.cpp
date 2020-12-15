#include "Solution.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	Solution smax;
	std::vector<int> v = {1,50,6,30,5,4,8,3};
	cout<<smax.maxArea(v)<<endl;
	return 0;
}