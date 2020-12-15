#include "Solution.h"
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
	std::vector<std::vector<int>> v = {{1,3,1},{1,5,1},{4,2,1}};
	Solution tet;
	cout<<tet.minPathSum(v)<<endl;
	return 0;
}