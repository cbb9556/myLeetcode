#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;

int main(int argc, char const *argv[]) {
	std::vector<int> v{0,1,3,4,5,7,8,9,10};
	Solution tet;
	cout<<tet.missingNumber(v)<<endl;
	return 0;
}