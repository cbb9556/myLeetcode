#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;

int main(int argc, char const *argv[]) {
	std::vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
	Solution tet;
	cout<<tet.maxSubArray(v)<<endl;
	return 0;
}